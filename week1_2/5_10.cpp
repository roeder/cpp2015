#include <cassert>
#include <iostream>
#include "5_10.h"

int main(int argc, char* argv[]) {
    // Test matrices
    double** Ptest;
    Ptest = AllocateMatrixMemory(5, 5);

    // Filling in P(kn)
    FillPkn(Ptest, 0, 3, 5);
    std::cout << "Matrix P(24) is\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout.flush() << Ptest[i][j] << " ";
        }
        std::cout.flush() << '\n';
    }

    // Cleanup
    FreeMatrixMemory(Ptest);

    return 0;
}

// Fill in the matrix P(kn)
void FillPkn(double **P, int k, int n, int N)
{
    assert(k <= n);
    assert(k < N && n < N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {

            P[i][j] = 0;

            if (i == n && j == k)
                P[i][j] = 1;

            if (i == k && j == n)
                P[i][j] = 1;

            if(i == j && i != k && i != n)
                P[i][j] = 1;
        }
    }
}

// Matrix times Matrix
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols)
{
    assert(BRows == ACols);

    for (int i = 0; i < ARows; ++i) {
        for (int j = 0; j < BCols; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < ACols; ++k) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Matrix times Vector
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows)
{
    assert(ACols == BRows);

    for (int i = 0; i < ARows; ++i) {
        res[i] = 0;
        for (int j = 0; j < ACols; ++j) {
            res[i] += A[i][j] * B[j];
        }
    }

}

double** AllocateMatrixMemory(int numRows, int numCols)
{
    double** matrix;
    matrix = new double* [numRows];
    for (int i=0; i<numRows; i++)
    {
        matrix[i] = new double [numCols];
    }
    return matrix;
}

void FreeMatrixMemory(int numRows, double ** matrix)
{
    for (int i = 0; i < numRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}