#include "PhdStudent.hpp"

PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime)
{
    this->name = name;
    tuition_fees = fees;
    SetLibraryFines(fines);
    this->fullTime = fullTime;
}

double PhdStudent::MoneyOwed() const
{
    return 0;
}