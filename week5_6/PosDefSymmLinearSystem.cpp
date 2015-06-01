#include <cmath>
#include <cassert>
#include "PosDefSymmLinearSystem.hpp"

PosDefSymmLinearSystem::PosDefSymmLinearSystem(const Matrix& A, const Vector& b, double epsilon)
{
    int n = b.GetSize();
    bool symm_check = true;

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (A(i, j) != A(j, i))
                symm_check = false;
        }
    }

    assert(symm_check);
    assert(A.GetNumberOfColumns() == n);
    assert(A.GetNumberOfRows() == n);

    mSize = n;
    mpA = new Matrix(A);
    mpb = new Vector(b);
    this->epsilon = epsilon;
}

Vector PosDefSymmLinearSystem::Solve()
{
    int n = mSize;
    Vector x(n);
    Vector x_next(n);

    Matrix& A = *mpA;
    Vector& b = *mpb;

    int k = 0;
    Vector r(n);
    Vector r_prev(n);
    r = b - A * x;

    Vector p(n);
    double beta = 0;

    while (r.CalculateNorm(2) >= epsilon)
    {
        if (k > 0)
            beta = (r * r) / (r_prev * r_prev);
        p = r + beta * p;
        alpha = (r *r) / ((p * A) * p);
        x_next = x + alpha * p;
        r_prev = r;
        r = b - A * x_next;
        k++;
    }
    return x;
}