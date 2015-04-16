#include "iostream"
#include "numeric"
#include "cmath"

int main(int argc, char* argv[]) {

    double a[] = {2.3, 4, 7};
    double b[] = {3, 1, 4.1};

    double p;
    p = a[1] * b[1] + a[2] * b[2] + a[0] * b[0];
    std::cout << "Scalar product is " << p << '\n';

    double n1, n2;
    n1 = sqrt(a[1] * a[1] + a[2] * a[2] + a[0] * a[0]);
    n2 = sqrt(b[1] * b[1] + b[2] * b[2] + b[0] * b[0]);

    std::cout << "First euclidean norm is " << n1 << '\n';
    std::cout << "Second euclidean norm is " << n2 << '\n';

    return 0;
}

