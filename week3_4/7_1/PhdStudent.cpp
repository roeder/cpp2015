#include "PhdStudent.hpp"

PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime)
{
    name = name;
    tuition_fees = fees;
    SetLibraryFines(fines);
    fullTime = fullTime;
}

double PhdStudent::MoneyOwed() const
{
    return 0;
}