#include "iostream"

void swap_pointer(double *a, double *b);
void swap_ref(double &a, double &b);

int main(int argc, char* argv[]) {
    double a, b;
    a = 5;
    b = 3;

    std::cout << "Before swapping: a = " << a << " b = " << b << "\n";

    swap_pointer(&a, &b);

    std::cout << "After swapping: a = " << a << " b = " << b << "\n";

    swap_ref(a, b);

    std::cout << "After ref swapping: a = " << a << " b = " << b << "\n";

    return 0;
}

void swap_pointer(double *a, double *b) {
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(double &a, double &b) {
    double temp;
    temp = a;
    a = b;
    b = temp;
}