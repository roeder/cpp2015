/*Below is some example code. The exercises below all require modification of this code. In all cases use a suitable
 * check to ensure your code is correct. */

/* 1. Set the variable x to the value 5 if either p is greater than or equal to q, or the variable j is not equal to 10.
2. Set the variable x to the value 5 if both y is greater than or equal to q, and the variable j is equal to 20. If this
 compound condition is not met, set x to take the same value as p.
 3. Setthevariablexaccordingtothefollowingrule. x = 0 if p > q; x = 1 if p <= q and j = 10; x = 2 otherwise. */

#include <iostream>
int main(int argc, char* argv[]) {
    double p, q, x, y;
    int j;

    // Question 1
    if (p >= q || j != 10) {
        x = 5;
    }

    // Question 2
    // Shorthand:
    // x = y >= q && j == 20 ? 5 : p;
    if (y >= q && j == 20) {
        x = 5;
    } else {
        x = p;
    }

    // Question 3
    x = 2;
    if (p > q) {
        x = 0;
    }
    if (p <= q && j == 10) {
        x = 1;
    }
    return 0;
}