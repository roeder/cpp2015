#include "Matrix2x2.hpp"

int main(int argc, char * argv[])
{
    Matrix2x2 m1;

    std::cout << "Test default constructor\nMatrix m1:\n";
    m1.Print();

    Matrix2x2 m2(4.2, 13, 8, 76);
    std::cout << "Test custom constructor\nMatrix m2:\n";
    m2.Print();

    Matrix2x2 m_copy(m2);
    std::cout << "Test copy constructor\nMatrix m_copy (copy of m2):\n";
    m_copy.Print();

    std::cout << "Test determinant: det(m2): " << m2.CalcDeterminant() << "\n";

    Matrix2x2 m2_inv;
    m2_inv = m2.CalcInverse();

    std::cout << "Test inverse: inv(m2):\n";
    m2_inv.Print();

    Matrix2x2 m3;
    m3 = m2_inv;
    std::cout << "Test assignment overload\nMatrix m3 = m2_inv:\n";
    m3.Print();

    Matrix2x2 m4;
    m4 = -m2;
    std::cout << "Test unary operator overload\nMatrix m4 = -m2:\n";
    m4.Print();

    Matrix2x2 m5(1,1,1,1);
    Matrix2x2 m6;
    m6 = m2 + m5;
    std::cout << "Test binary + overload\n";
    m6.Print();

    m6 = m4 - m5;
    std::cout << "Test binary - overload\n";
    m6.Print();

    m6.MultScalar(2.5);
    std::cout << "Test scalar multiplication\n";
    m6.Print();

    return 0;
}