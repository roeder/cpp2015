#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "PhdStudent.hpp"

#include <iostream>

int main(int argc, char * argv[])
{
    Student Timo("Timo", 10, 500);

    std::cout << Timo.tuition_fees << "\n";

    PhdStudent Hans("Hans", 30, 10000, 1);

    std::cout << Hans.GetLibraryFines() << "\n";

    Hans.SetLibraryFines(-42);

    std::cout << "First test: set(-42): " << Hans.GetLibraryFines() << "\n";

    Hans.SetLibraryFines(42);

    std::cout << "Second test: set(42): " << Hans.GetLibraryFines() << "\n";

    return 0;
}

/*
500
30
First test: set(-42): 30
Second test: set(42): 42
*/