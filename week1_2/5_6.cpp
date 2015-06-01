#include "iostream"
#include "5_6.h"
#include "cassert"

//int main(int argc, char* argv[]) {
//    // Test matrices
//    double** A;
//    double** B;
//
//    A = AllocateMatrixMemory(2, 3);
//    B = AllocateMatrixMemory(3, 4);
//
//    std::cout << "Matrix A is\n";
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            A[i][j] = 1 + j + 3 * i;
//            std::cout.flush() << A[i][j] << " ";
//        }
//        std::cout.flush() << '\n';
//    }
//
//    std::cout << "Matrix B is\n";
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            B[i][j] = 1 + j + 4 * i;
//            std::cout.flush() << B[i][j] << " ";
//        }
//        std::cout.flush() << '\n';
//    }
//
//    // Test vector
//    double* u;
//    u = new double[3];
//
//    std::cout << "Vector u is\n";
//    for (int k = 0; k < 3; ++k) {
//        u[k] = k + 1;
//        std::cout.flush() << u[k] << "\n";
//    }
//
//    // Matrix times matrix
//    double** C;
//    C = AllocateMatrixMemory(2, 4);
//    Multiply(C, A, B, 2, 3, 3, 4);
//
//    std::cout << "Matrix C = AB is\n";
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            std::cout.flush() << C[i][j] << " ";
//        }
//        std::cout.flush() << '\n';
//    }
//
//    // Vector times matrix
//    double* t;
//    t = new double[4];
//    Multiply(t, u, B, 3, 3, 4);
//
//    std::cout << "Vector t = u*B is\n";
//    for (int k = 0; k < 4; ++k) {
//        std::cout.flush() << t[k] << "\n";
//    }
//
//    // Scalar times matrix
//    double** D;
//    D = AllocateMatrixMemory(2, 3);
//
//    Multiply(D, 3, A, 2, 3);
//    std::cout << "Matrix D = 3A is\n";
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            std::cout.flush() << D[i][j] << " ";
//        }
//        std::cout.flush() << '\n';
//    }
//
//    Multiply(D, A, 4, 2, 3);
//    std::cout << "Matrix D = A * 4 is\n";
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            std::cout.flush() << D[i][j] << " ";
//        }
//        std::cout.flush() << '\n';
//    }
//
//    // Cleanup
//    FreeMatrixMemory(2, A);
//    FreeMatrixMemory(3, B);
//    FreeMatrixMemory(2, C);
//    FreeMatrixMemory(2, D);
//    delete[] u;
//    delete[] t;
//
//    return 0;
//}

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

// Column Vector times Matrix
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols)
{
    assert(ACols == BRows);

    for (int j = 0; j < BCols; ++j) {
        res[j] = 0;
        for (int i = 0; i < BRows; ++i) {
            res[j] += A[i] * B[i][j];
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

// Scalar times matrix
void Multiply(double **res, double scalar, double **B, int BRows, int BCols)
{
    for (int i = 0; i < BRows; ++i) {
        for (int j = 0; j < BCols; ++j) {
            res[i][j] = scalar * B[i][j];
        }
    }
}

// Matrix times scalar (same as before)
void Multiply(double **res, double **B, double scalar, int BRows, int BCols)
{
    for (int i = 0; i < BRows; ++i) {
        for (int j = 0; j < BCols; ++j) {
            res[i][j] = scalar * B[i][j];
        }
    }
}

//double** AllocateMatrixMemory(int numRows, int numCols)
//{
//    double** matrix;
//    matrix = new double* [numRows];
//    for (int i=0; i<numRows; i++)
//    {
//        matrix[i] = new double [numCols];
//    }
//    return matrix;
//}
//
//void FreeMatrixMemory(int numRows, double ** matrix)
//{
//    for (int i = 0; i < numRows; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//}
