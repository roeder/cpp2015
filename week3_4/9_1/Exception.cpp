#include <iostream>
#include "Exception.hpp"

Exception::Exception()
{
    mTag = "unspecified";
    mProblem = "unspecified";
}

Exception::Exception(std::string tagString, std::string probString)
{
    mTag = tagString;
    mProblem = probString;
}

void Exception::PrintDebug() const
{
    std::cerr << "** Error ("<<mTag<<") **\n";
    std::cerr << "Problem: " << mProblem << "\n\n";
}

void Exception::SetProblem(std::string probString)
{
    mProblem = probString;
}

void Exception::SetTag(std::string tagString)
{
    mTag = tagString;
}