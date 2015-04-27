#include "iostream"
#include "numeric"
#include "cmath"

int main(int argc, char* argv[]) {

    double epsilon;
    epsilon = 0.1;

    double x_prev;
    x_prev = 10;

    double x_next;
    x_next = 0;

    const double e = 2.71828;
    double fx, der_fx;

    int i;
    i = 1;

    while (std::abs(x_next - x_prev) >= epsilon) {
        x_prev = x_next;
        fx = pow(e, x_prev) + pow(x_prev, 3) - 5;
        der_fx = 3 * pow(x_prev, 2) + pow(e, x_prev);
        x_next = x_prev - (fx / der_fx);
        std::cout.flush() << "Iteration " << i << ": " << x_next << '\n';
        i++;
    }

    return 0;
}
