#include <iostream>

int main(int argc, char* argv[]) {

    int cars[] = {34, 58, 57, 32, 43};
    double out1;

    out1 = double(cars[0] + cars[1] + cars[2] + cars[3] + cars[4]) / 5.0;

    std::cout << "Average number of cars is " << out1 << "\n";

    return 0;
}

