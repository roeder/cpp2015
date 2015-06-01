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
    double alpha;

    while (r.CalculateNorm() >= epsilon)
    {
        if (k > 0)
        {
            beta = (r * r) / (r_prev * r_prev);
            x = x_next;
        }
        p = r + p * beta;
        alpha = (r *r) / ((p * A) * p);
        x_next = x + p * alpha;
        r_prev = r;
        r = b - A * x_next;
        ++k;
        std::cout << r.CalculateNorm() << "\n";
    }
    return x;
}