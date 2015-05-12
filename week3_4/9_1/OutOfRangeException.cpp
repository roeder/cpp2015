#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string prob)
{
    SetTag("OUT_OF_RANGE");
    SetProblem(prob);
}