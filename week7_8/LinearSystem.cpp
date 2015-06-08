#include <cmath>
#include <cassert>
#include "LinearSystem.hpp"

//LinearSystem::LinearSystem(const LinearSystem &otherLinearSystem)
//{
//    mSize = otherLinearSystem.mSize;
//    mpA = otherLinearSystem.mpA;
//    mpb = otherLinearSystem.mpb;
//}

LinearSystem::LinearSystem(const Matrix& A, const Vector& b)
{
    int system_size = b.GetSize();
    assert(A.GetNumberOfColumns() == system_size);
    assert(A.GetNumberOfRows() == system_size);

    mSize = system_size;
    mpA = new Matrix(A);
    mpb = new Vector(b);
}

LinearSystem::~LinearSystem()
{
    delete mpA;
    delete mpb;
}

Vector LinearSystem::Solve()
{
    int n = mSize;
    Vector u(n);

    Matrix& A = *mpA;
    Vector& b = *mpb;

    // First outer loop: obtain triangular form
    for (int k = 0; k < n; ++k) {

        // Initialise values for finding row with highest value within column k
        int max_row = k;
        double max_value = std::abs(A(k + 1, k + 1));

        // Loop through all rows below k to find max
        for (int m = k + 1; m < n; ++m) {

            if (std::abs(A(m + 1, k + 1)) > max_value) {
                max_row = m;
                max_value = std::abs(A(m + 1, k + 1));
            }
        }

        // Swap rows by looping through columns
        for (int l = k; l < n; ++l) {
            double temp = A(max_row + 1, l +1);
            A(max_row + 1, l +1) = A(k + 1, l +1);
            A(k + 1, l + 1) = temp;
        }

        // Swap rows in the vector b
        double tmp = b[max_row];
        b[max_row] = b[k];
        b[k] = tmp;

        // Loop i through all rows below k
        for (int i = k + 1; i < n; ++i) {

            // Loop j through all columns to the right of k
            for (int j = k + 1; j < n; ++j) {
                A(i + 1, j + 1) = A(i + 1, j + 1) - A(k + 1, j + 1) * (A(i + 1, k + 1) / A(k + 1, k + 1));
            }

            // Adjust vector b
            b[i] = b[i] - b[k] * (A(i + 1, k + 1) / A(k + 1, k + 1));

            // Set lower triangular matrix to 0
            A(i + 1, k + 1) = 0;

        }
    }

    // Initial value for result vector u
    u[n - 1] = b[n - 1] / A(n, n);

    // Second outer loop: back-substitution to solve u
    for (int k = n - 2; k > -1 ; --k) {

        double temp;
        temp = 0;

        for (int i = k + 1; i < n; ++i) {
            temp += A(k + 1, i + 1) * u[i];
        }

        u[k] = (b[k] - temp) / A(k + 1, k + 1);
    }
    return u;
}
