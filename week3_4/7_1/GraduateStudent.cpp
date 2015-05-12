#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent() : Student()
{
    fullTime = 0;
}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime)
{
    this->name = name;
    tuition_fees = fees;
    SetLibraryFines(fines);
    this->fullTime = fullTime;
}

double GraduateStudent::MoneyOwed() const
{
    return GetLibraryFines();
}