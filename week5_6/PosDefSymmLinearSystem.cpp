#include <cmath>
#include <cassert>
#include "PosDefSymmLinearSystem.hpp"

PosDefSymmLinearSystem::PosDefSymmLinearSystem(const Matrix& A, const Vector& b, double epsilon):LinearSystem(A, b)
{
//    int n = b.GetSize();
//
//    mSize = n;
//    mpA = new Matrix(A);
//    mpb = new Vector(b);
    this->epsilon = epsilon;
}

Vector PosDefSymmLinearSystem::Solve()
{
    int n = mSize;

    Matrix& A = *mpA;
    Vector& b = *mpb;

    int k;

    Vector r(n);
    Vector r_prev(n);

    double alpha;
    double beta;
    Vector x(n);
    Vector x_next(n);

    k = 0;
    r = b - A * x;
    Vector p(n);
    beta = 0;

    while (r.CalculateNorm() >= epsilon)
    {
        if (k > 0)
            beta = (r * r) / (r_prev * r_prev);

        p = r + p * beta;
        alpha = (r *r) / (p * A * p);
        x = x + p * alpha;
        r_prev = r;
        r = b - A * x;
        k++;
        std::cout << r.CalculateNorm() << "\n";
    }
    return x;
}