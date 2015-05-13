#include "AbstractOdeSolver.hpp"

AbstractOdeSolver::AbstractOdeSolver()
{
    stepSize = 0.1;
    initialTime = 0.0;
    finalTime = 1.0;
    initialValue = 1.0;
}

void AbstractOdeSolver::SetStepSize(double h)
{
    stepSize = h;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1)
{
    initialTime = t0;
    finalTime = t1;
}

void AbstractOdeSolver::SetInitialValue(double y0)
{
    initialValue = y0;
}