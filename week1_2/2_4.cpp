/* This exercise uses the following vectors and matrices: u, v, A, B.
 * Furthermore, the vector w satisfies w = u − 3v. These vectors and matrices are stored in arrays using the following
 * program. This program includes code to calculate the vector w. */

#include <iostream>
int main(int argc, char* argv[])
{
    double u[3] = {1.0, 2.0, 3.0};
    double v[3] = {6.0, 5.0, 4.0};
    double A[3][3] = {{1.0, 5.0, 0.0},
                      {7.0, 1.0, 2.0},
                      {0.0, 0.0, 1.0}};
    double B[3][3] = {{-2.0, 0.0, 1.0},
                      {1.0, 0.0, 0.0},
                      {4.0, 1.0, 0.0}};

    double w[3];
    for (int i=0; i<3; i++)
    {
        w[i] = u[i] - 3.0*v[i];
    }

    return 0;
}

/* We now define vectors x, y, and z, and matrices C and D, such that
 *
 * x = u − v,
 * y = Au,
 * z = Au − v,
 * C = 4A − 3B,
 * D = AB.
 *
 * Develop the program above to calculate the vectors x, y, and z and the matrices C and D, using loops where possible.
 * Hint: make sure you define arrays of an appropriate size for these variables. Check your answer by printing out
 * the results, and comparing with direct calculation.