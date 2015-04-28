#include <iostream>
#include <cmath>
#include "5_4.h"

int main(int argc, char* argv[]) {

    double* a;
    double* b;
    a = new double[10];
    b = new double[10];

    for (int i = 0; i < 10; ++i) {
        a[i] = ((double) (i));
        b[i] = 2.0 * a[i];
    }

    double* c;
    c = new double[1];
    c[0] = 5.0;

    std::cout << "Mean of a: " << calc_mean(a, 10) << "\n";
    std::cout << "Mean of b: " << calc_mean(b, 10) << "\n";
    std::cout << "Mean of c: " << calc_mean(c, 1) << "\n";

    std::cout << "SD of a: " << calc_std(a, 10) << "\n";
    std::cout << "SD of b: " << calc_std(b, 10) << "\n";
    std::cout << "SD of c: " << calc_std(c, 1) << "\n";

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

double calc_std(double a[], int length){
    double mean;
    mean = calc_mean(a, length);

    int denumerator = length - 1;

    if (length == 1)
        denumerator = length;

    double temp = 0.0;

    for (int i = 0; i < length; ++i) {
        temp += pow(a[i] - mean, 2);
    }

    return sqrt(temp / denumerator);
}
double calc_mean(double a[], int length){
    double temp = 0.0;

    for (int i = 0; i < length; ++i) {
        temp += a[i];
    }

    return temp / ((double) length);
}