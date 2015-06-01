#include <cassert>
#include <iostream>
#include <fstream>
#include "3_3.h"

//int main(int argc, char* argv[]) {
//
//    implicit_Euler(25);
//
//    return 0;
//}

void implicit_Euler(int n)
{
    assert(n > 1);

    double h;
    h = 1 / ((double) n);

    double y[n];
    y[0] = 1;

    double x;
    x = 0;

    std::ofstream write_file("xy.dat");
    assert(write_file.is_open());

    write_file << 0 << "," << 1 << "\n";

    for (int i = 1; i < n + 1; ++i) {
        y[i] = y[i - 1] / (1 + h);
        x += h;
        write_file << x << "," << y[i] << "\n";
        write_file.flush();
    }
    write_file.close();
}