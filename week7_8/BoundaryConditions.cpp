#include <cassert>
#include "BoundaryConditions.hpp"

BoundaryConditions::BoundaryConditions()
{
   mLhsBcIsDirichlet = false;
   mRhsBcIsDirichlet = false;
   mLhsBcIsNeumann = false;
   mRhsBcIsNeumann = false;
}

void BoundaryConditions::SetLhsDirichletBc(double lhsValue)
{
   mLhsBcIsNeumann = false;
   mLhsBcIsDirichlet = true;
   mLhsBcValue = lhsValue;
}

void BoundaryConditions::SetRhsDirichletBc(double rhsValue)
{
   mRhsBcIsNeumann = false;
   mRhsBcIsDirichlet = true;
   mRhsBcValue = rhsValue;
}

void BoundaryConditions::SetLhsNeumannBc(double lhsDerivValue)
{
   mLhsBcIsDirichlet = false;
   mLhsBcIsNeumann = true;
   mLhsBcValue = lhsDerivValue;
}

void BoundaryConditions::SetRhsNeumannBc(double rhsDerivValue)
{
   mRhsBcIsDirichlet = false;
   mRhsBcIsNeumann = true;
   mRhsBcValue = rhsDerivValue;
}
