#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob)
{
    SetTag("FILE_NOT_OPEN");
    SetProblem(prob);
}