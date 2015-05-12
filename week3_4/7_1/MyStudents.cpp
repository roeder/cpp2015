#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "PhdStudent.hpp"

#include <iostream>

int main(int argc, char * argv[])
{
    Student Timo("Timo", 10, 500);

    std::cout << Timo.tuition_fees << "\n";

    PhdStudent Janine("Janine", 30, 10000, 1);

    std::cout << Janine.GetLibraryFines() << "\n";

    Janine.SetLibraryFines(-42);

    std::cout << "First test: set(-42): " << Janine.GetLibraryFines() << "\n";

    Janine.SetLibraryFines(42);

    std::cout << "Second test: set(42): " << Janine.GetLibraryFines() << "\n";

    return 0;
}