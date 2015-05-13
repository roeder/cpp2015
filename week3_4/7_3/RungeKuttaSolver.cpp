#include "RungeKuttaSolver.hpp"

RungeKuttaSolver::RungeKuttaSolver(double (*f)(double y, double t))
{
    right = f;
}

double RungeKuttaSolver::RightHandSide(double y, double t)
{
    return right(y, t);
}

double RungeKuttaSolver::SolveEquation()
{
    double h = GetStepSize();
    double t_previous = GetInitialTime();
    double t1 = GetFinalTime();
    double y_previous = getInitialValue();

    double y_current = getInitialValue();
    double k1, k2, k3, k4;

    while (t_previous + h < t1)
    {
        k1 = h * RightHandSide(y_previous, t_previous);
        k2 = h * RightHandSide(y_previous + 0.5 * k1, t_previous + 0.5 * h);
        k3 = h * RightHandSide(y_previous + 0.5 * k2, t_previous + 0.5 * h);
        k4 = h * RightHandSide(y_previous + k3, t_previous + h);

        y_current = y_previous + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);

        t_previous += h;
        y_previous = y_current;
    }

    return y_current;
}