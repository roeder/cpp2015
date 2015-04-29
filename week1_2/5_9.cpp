//#include <cassert>
#include <cmath>
#include <iostream>
#include "5_9.h"

int main(int argc, char* argv[]) {

    double** A;
    A = AllocateMatrixMemory(3, 3);

    A[0][0] = 1;
    A[0][1] = -1;
    A[0][2] = 2;
    A[1][0] = 0;
    A[1][1] = 0;
    A[1][2] = -1;
    A[2][0] = 0;
    A[2][1] = 2;
    A[2][2] = -1;

    std::cout << "Matrix A is\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout.flush() << A[i][j] << " ";
        }
        std::cout.flush() << '\n';
    }

    double* b;
    b = new double[3];

    b[0] = 8;
    b[1] = -11;
    b[2] = -3;

    std::cout << "Vector b is\n";
    for (int k = 0; k < 3; ++k) {
        std::cout.flush() << b[k] << "\n";
    }

    double* u;
    u = new double[3];

    solve3by3(A, b, u);

    PrintTriangular(A, b, 3);

    std::cout << "Solved vector u is\n";
    for (int k = 0; k < 3; ++k) {
        std::cout.flush() << u[k] << "\n";
    }

    FreeMatrixMemory(3, A);
    delete[] b;
    delete[] u;

    return 0;
}

void solve3by3(double **A, double *b, double *u){

    int n = 3;

    // First outer loop: obtain triangular form
    for (int k = 0; k < n; ++k) {

        // Initialise values for finding row with highest value within column k
        int max_row = k;
        double max_value = std::abs(A[k][k]);

        // Loop through all rows below k to find max
        for (int m = k + 1; m < n; ++m) {

            if (std::abs(A[m][k]) > max_value) {
                max_row = m;
                max_value = std::abs(A[m][k]);
            }
        }

        // Swap rows by looping through columns
        for (int l = k; l < n; ++l) {
            double temp = A[max_row][l];
            A[max_row][l] = A[k][l];
            A[k][l] = temp;
        }

        // Swap rows in the vector b
        double tmp = b[max_row];
        b[max_row] = b[k];
        b[k] = tmp;

        // Loop i through all rows below k
        for (int i = k + 1; i < n; ++i) {

            // Loop j through all columns to the right of k
            for (int j = k + 1; j < n; ++j) {
                A[i][j] = A[i][j] - A[k][j] * (A[i][k] / A[k][k]);
            }

            // Adjust vector b
            b[i] = b[i] - b[k] * (A[i][k] / A[k][k]);

            // Set lower triangular matrix to 0
            A[i][k] = 0;

        }
    }

    // Initial value for result vector u
    u[n - 1] = b[n - 1] / A[n - 1][n - 1];

    // Second outer loop: back-substitution to solve u
    for (int k = n - 2; k > -1 ; --k) {

        double temp;
        temp = 0;

        for (int i = k + 1; i < n; ++i) {
            temp += A[k][i] * u[i];
        }

        u[k] = (b[k] - temp) / A[k][k];
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

void PrintTriangular(double** A, double* b, int n)
{
    std::cout << "Triangular system:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout.flush() << A[i][j] << " ";
        }
        std::cout.flush() << "| " << b[i] << '\n';
    }
}

void PrintSquareMatrix(double** A, int n)
{
    std::cout << "Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout.flush() << A[i][j] << " ";
        }
        std::cout.flush() << '\n';
    }
}