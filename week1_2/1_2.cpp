#include <iostream>

int main(int argc, char* argv[]) {

    int in1;
    int in2;
    int out1;

    std::cout << "Enter first number\n";
    std::cin >> in1;

    std::cout << "Enter second number\n";
    std::cin >> in2;

    out1 = in1 * in2;

    std::cout << "Product is " << out1 << "\n";

    return 0;
}
