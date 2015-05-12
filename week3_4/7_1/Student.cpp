#include "Student.hpp"
#include <cassert>

Student::Student()
{
    name = "unspecified";
    tuition_fees = 0.0;
    library_fines = 0.0;
}

Student::Student(std::string name, double fines, double fees)
{
    this->name = name;
    tuition_fees = fees;
    library_fines = fines;
}

double Student::MoneyOwed() const
{
    return tuition_fees + library_fines;
}

void Student::SetLibraryFines(double amount)
{
    if(amount > 0)
        library_fines = amount;
}

double Student::GetLibraryFines() const{
    return library_fines;
}