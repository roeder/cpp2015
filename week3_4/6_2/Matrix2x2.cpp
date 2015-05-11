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

// Print method for 2x2 matrix
void Matrix2x2::Print() const
{
    std::cout << val00 << " " << val01 << "\n" << val10 << " " << val11 << "\n";
}