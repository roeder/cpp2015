#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "PhdStudent.hpp"

#include <iostream>

int main(int argc, char * argv[])
{
    Student Timo("Timo", 10, 500);

    std::cout << Timo.MoneyOwed() << "\n";

    PhdStudent Janine("Janine", 30, 10000, 1);

    std::cout << Janine.MoneyOwed() << "\n";

    return 0;
}