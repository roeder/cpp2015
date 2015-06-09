#include <iostream>
#include <fstream>
#include <cassert>
#include "BvpOde.hpp"

BvpOde::BvpOde(SecondOrderOde* pOde, BoundaryConditions* pBcs, int numNodes)
{
   mpOde = pOde;
   mpBconds = pBcs;

   mNumNodes = numNodes;
   mpGrid = new FiniteDifferenceGrid(mNumNodes, pOde->mXmin, pOde->mXmax);

   mpSolVec = new Vector(mNumNodes);
   mpRhsVec = new Vector(mNumNodes);
   mpLhsMat = new Matrix(mNumNodes, mNumNodes);

   mFilename = "default_output.dat";
   mpLinearSystem = NULL;
}

BvpOde::~BvpOde()
{
   delete mpSolVec;
   delete mpRhsVec;
   delete mpLhsMat;
   delete mpGrid;

   if (mpLinearSystem)
   {
      delete mpLinearSystem;
   }
}

void BvpOde::Solve()
{
   PopulateMatrix();
   PopulateVector();
   ApplyBoundaryConditions();
   mpLinearSystem = new LinearSystem(*mpLhsMat, *mpRhsVec);
   *mpSolVec = mpLinearSystem->Solve();
   WriteSolutionFile();
}

void BvpOde::PopulateMatrix()
{
   for (int i = 1; i < mNumNodes - 1; i++)
   {
      double x_prev, x, x_next;

      x = mpGrid->mNodes[i].coordinate;
      x_prev = mpGrid->mNodes[i - 1].coordinate;
      x_next = mpGrid->mNodes[i + 1].coordinate;

      double alpha, beta, gamma;

      alpha = 2.0/(x_next - x_prev)/(x - x_prev);
      beta = -2.0/(x_next - x)/(x - x_prev);
      gamma = 2.0/(x_next - x_prev)/(x_next - x);

      (*mpLhsMat)(i + 1, i) = (mpOde->mCoeffOfUxx) * alpha - (mpOde->mCoeffOfUx) / (x_next - x_prev);
      (*mpLhsMat)(i + 1, i + 1) = (mpOde->mCoeffOfUxx) * beta + mpOde->mCoeffOfU;
      (*mpLhsMat)(i + 1, i + 2) = (mpOde->mCoeffOfUxx) * gamma + (mpOde->mCoeffOfUx) / (x_next - x_prev);
   }
}

void BvpOde::PopulateVector()
{
   for (int i = 1; i < mNumNodes - 1; i++)
   {
      double x = mpGrid->mNodes[i].coordinate;
      (*mpRhsVec)(i + 1) = mpOde->mpRhsFunc(x);
   }
}

void BvpOde::ApplyBoundaryConditions()
{
   if (mpBconds->mLhsBcIsDirichlet)
   {
      (*mpLhsMat)(1, 1) = 1.0;
      (*mpRhsVec)(1) = mpBconds->mLhsBcValue;
   }

   if (mpBconds->mRhsBcIsDirichlet)
   {
      (*mpLhsMat)(mNumNodes, mNumNodes) = 1.0;
      (*mpRhsVec)(mNumNodes) = mpBconds->mRhsBcValue;
   }

   if (mpBconds->mLhsBcIsNeumann)
   {
      double h = mpGrid->mNodes[1].coordinate - mpGrid->mNodes[0].coordinate;
      (*mpLhsMat)(1, 1) = -1.0 / h;
      (*mpLhsMat)(1, 2) = 1.0 / h;
      (*mpRhsVec)(1) = mpBconds->mLhsBcValue;
   }

   if (mpBconds->mRhsBcIsNeumann)
   {
      double h = mpGrid->mNodes[mNumNodes - 1].coordinate - mpGrid->mNodes[mNumNodes - 2].coordinate;
      (*mpLhsMat)(mNumNodes, mNumNodes - 1) = -1.0 / h;
      (*mpLhsMat)(mNumNodes, mNumNodes) = 1.0 / h;
      (*mpRhsVec)(mNumNodes) = mpBconds->mRhsBcValue;
   }
}

void BvpOde::WriteSolutionFile()
{
   std::ofstream output_file(mFilename.c_str());
   assert(output_file.is_open());
   for (int i = 0; i < mNumNodes; i++)
   {
      double x = mpGrid->mNodes[i].coordinate;
      output_file << x << "  " << (*mpSolVec)(i + 1) << "\n";
   }
   output_file.flush();
   output_file.close();
}
