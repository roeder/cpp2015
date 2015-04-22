/* This exercise uses the following vectors and matrices: u, v, A, B.
 * Furthermore, the vector w satisfies w = u − 3v. These vectors and matrices are stored in arrays using the following
 * program. This program includes code to calculate the vector w.
 * We now define vectors x, y, and z, and matrices C and D, such that
 *
 * x = u − v,
 * y = Au,
 * z = Au − v,
 * C = 4A − 3B,
 * D = AB */

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
        w[i] = u[i] - 3.0 * v[i];
    }

    std::cout << "Vector x = u - v is\n";
    double x[3];
    for (int j = 0; j < 3; j++) {
        x[j] = u[j] - v[j];
        std::cout.flush() << x[j] << '\n';
    }

    std::cout << "Vector y = Au is\n";
    double y[3];
    for (int i = 0; i < 3; ++i) {
        y[i] = 0;
        for (int j = 0; j < 3; ++j) {
            y[i] += A[i][j] * u[j];
        }
        std::cout.flush() << y[i] << '\n';
    }

    std::cout << "Vector z = Au - v is\n";
    double z[3];
    for (int i = 0; i < 3; ++i) {
        z[i] = 0;
        for (int j = 0; j < 3; ++j) {
            z[i] += A[i][j] * u[j];
        }
        z[i] -= v[i];
        std::cout.flush() << z[i] << '\n';
    }

    std::cout << "Matrix C = 4A - 3B is\n";
    double C[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            C[i][j] = 4 * A[i][j] - 3 * B[i][j];
            std::cout.flush() << C[i][j] << " ";
        }
        std::cout.flush() << '\n';
    }

    std::cout << "Matrix D = AB is\n";
    double D[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            D[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                D[i][j] += A[i][k] * B[k][j];
            }
            std::cout.flush() << D[i][j] << " ";
        }
        std::cout.flush() << '\n';
    }

    return 0;
}