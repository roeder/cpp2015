#include "Matrix2x2.hpp"

// Override default constructor
// Set all values to zero
Matrix2x2::Matrix2x2()
{
    val00 = 0.0;
    val01 = 0.0;
    val10 = 0.0;
    val11 = 0.0;
}

// Copy constructor
Matrix2x2::Matrix2x2(const Matrix2x2& other)
{
    val00 = other.Getval00();
    val01 = other.Getval01();
    val10 = other.Getval10();
    val11 = other.Getval11();
}

// Constructor with four arguments
Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
    val00 = a;
    val01 = b;
    val10 = c;
    val11 = d;
}

double Matrix2x2::CalcDeterminant() const
{
    return (val00 * val11) - (val01 * val10);
}

Matrix2x2 Matrix2x2::CalcInverse() const
{
    double det;
    det = (val00 * val11) - (val01 * val10);

    assert(det != 0);

    return Matrix2x2(val11 / det, -val01 / det, -val10 / det, val00 / det);
}

Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z)
{
    val00 = z.val00;
    val01 = z.val01;
    val10 = z.val10;
    val11 = z.val11;
    return *this;
}

Matrix2x2 Matrix2x2::operator-() const
{
    return Matrix2x2(-val00, -val01, -val10, -val11);
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const
{
    Matrix2x2 w;

    w.val00 = val00 + z.val00;
    w.val01 = val01 + z.val01;
    w.val10 = val10 + z.val10;
    w.val11 = val11 + z.val11;

    return w;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const
{
    Matrix2x2 w;

    w.val00 = val00 - z.val00;
    w.val01 = val01 - z.val01;
    w.val10 = val10 - z.val10;
    w.val11 = val11 - z.val11;

    return w;
}

void Matrix2x2::MultScalar(double scalar)
{
    val00 = scalar * val00;
    val01 = scalar * val01;
    val10 = scalar * val10;
    val11 = scalar * val11;
}

// Print method for 2x2 matrix
void Matrix2x2::Print() const
{
    std::cout << val00 << " " << val01 << "\n" << val10 << " " << val11 << "\n";
}