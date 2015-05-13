#include "FowardEulerSolver.hpp"

FowardEulerSolver::FowardEulerSolver(double (*f)(double y, double t))
{
    right = f;
}

double FowardEulerSolver::RightHandSide(double y, double t)
{
    return right(y, t);
}

double FowardEulerSolver::SolveEquation()
{
    double h = GetStepSize();
    double t_previous = GetInitialTime();
    double t1 = GetFinalTime();
    double y_previous = getInitialValue();

    double y_current = getInitialValue();

    while (t_previous + h < t1)
    {
        y_current = y_previous + h * RightHandSide(y_previous, t_previous);
        t_previous += h;
        y_previous = y_current;
    }

    return y_current;
}