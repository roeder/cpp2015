#include "iostream"
#include "numeric"
#include "cmath"
#include "2_6.h"

//int main(int argc, char* argv[]) {
//
//    std::cout.flush() << newton_Raphson(0, 0.1);
//
//    return 0;
//}

double newton_Raphson(double initialGuess, double epsilon)
{
    double x_prev;
    x_prev = initialGuess + 2 * epsilon;

    const double e = 2.71828;
    double fx, der_fx;

    int i;
    i = 1;

    while (std::abs(initialGuess - x_prev) >= epsilon) {
        x_prev = initialGuess;
        fx = pow(e, x_prev) + pow(x_prev, 3) - 5;
        der_fx = 3 * pow(x_prev, 2) + pow(e, x_prev);
        initialGuess = x_prev - (fx / der_fx);
        i++;
    }

    return initialGuess;
}