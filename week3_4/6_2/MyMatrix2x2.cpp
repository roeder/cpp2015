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

    return 0;
}