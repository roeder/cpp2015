#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string prob)
{
    mTag = "OUT_OF_RANGE";
    mProblem = prob;
}