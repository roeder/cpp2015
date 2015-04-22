/* The inverse of a square matrix of size 2 is given in Sect. A.1.3.
 *
 * 1. Write code to calculate the inverse of the matrix given by A = {{4, 10},{1, 1}}
 * 2. Check that the inverse calculated is correct by printing out the entries of the inverse, and comparing
 * with direct calculation.
 * 3. Modify your code to include an assert statement that checks that the determinant of the matrix is nonzero.*/

#include <iostream>
#include "cassert"
#include "cmath"

int main(int argc, char* argv[]) {

    int A[2][2] = {{4, 10}, {1, 1}};
    int det_A;

    det_A = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    assert(det_A != 0);

    double inv_A[2][2];

    std::cout << "Inverse matrix is\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (i == j) {
                inv_A[i][j] = A[std::abs(i -1)][std::abs(j -1)] / double(det_A);
            } else {
                inv_A[i][j] = -A[i][j] / double(det_A);
            }
            std::cout.flush() << inv_A[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}