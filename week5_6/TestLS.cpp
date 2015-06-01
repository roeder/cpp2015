#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"
#include "PosDefSymmLinearSystem.hpp"

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

    Matrix m1(2, 4);

    std::cout << "Test default constructor\nMatrix m1:\n";
    m1.Print();

    for (int j = 0; j < 2; ++j)
    {
        for (int k = 0; k < 4; ++k)
        {
            m1.SetValue(j + k, j, k);
        }
    }

    std::cout << "Test assignment via SetValue method\nMatrix m1:\n";
    m1.Print();

    Matrix A(3, 3);

    A(1, 1) = 1;
    A(1, 2) = -1;
    A(1, 3) = 2;
    A(2, 1) = 0;
    A(2, 2) = 0;
    A(2, 3) = -1;
    A(3, 1) = 0;
    A(3, 2) = 2;
    A(3, 3) = -1;

    std::cout << "Test Gaussian Solve method - Matrix A:\n";
    A.Print();

    Vector b(3);

    b[0] = 8;
    b[1] = -11;
    b[2] = -3;

    std::cout << "Vector b:\n";
    b.Print();

    LinearSystem ls1(A, b);

    Vector solution(3);

    solution = ls1.Solve();

    std::cout << "Solution:\n";
    solution.Print();

    std::cout << "Scalar product: b * b:\n" << b * b << "\n";

    Matrix A2(3, 3);

    A2(1, 1) = 1;
    A2(1, 2) = 4;
    A2(1, 3) = 7;
    A2(2, 1) = 4;
    A2(2, 2) = 1;
    A2(2, 3) = 2;
    A2(3, 1) = 7;
    A2(3, 2) = 2;
    A2(3, 3) = 1;

    std::cout << "Test Gradient Solve method - Matrix A2:\n";
    A2.Print();

    Vector b2(3);

    b2[0] = 5;
    b2[1] = 2;
    b2[2] = 8;

    std::cout << "Vector b2:\n";
    b2.Print();

    PosDefSymmLinearSystem ls2(A2, b2, 0.0001);

    Vector solution2(3);

    solution2 = ls2.Solve();

    std::cout << "Solution:\n";
    solution2.Print();

    return 0;
}

/*
Test default constructor
Vector v1:
0 0 0 0 0
Assign 0-4 to Vector v1:
0 1 2 3 4
Test default constructor
Matrix m1:
0 0 0 0
0 0 0 0
Test assignment via SetValue method
Matrix m1:
0 1 2 3
1 2 3 4
Test Gaussian Solve method - Matrix A:
1 -1 2
0 0 -1
0 2 -1
Vector b:
8 -11 -3
Solution:
-10 4 11
Scalar product: b * b:
194
 */