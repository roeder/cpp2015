#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    Vector v1(5);

    std::cout << "Test default constructor\nVector v1:\n";
    v1.Print();

    for (int i = 0; i < 5; ++i) {
        v1.SetValue(i, i);
    }

    std::cout << "Assign 0-4 to Vector v1:\n";
    v1.Print();

    Matrix m1(4, 2);

    std::cout << "Test default constructor\nMatrix m1:\n";
    m1.Print();

    return 0;
}
