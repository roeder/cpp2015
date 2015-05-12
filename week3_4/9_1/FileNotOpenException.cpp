#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob)
{
    mTag = "FILE_NOT_OPEN";
    mProblem = prob;
}