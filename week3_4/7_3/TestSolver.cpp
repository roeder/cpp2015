#include "AbstractOdeSolver.hpp"
#include "FowardEulerSolver.hpp"
#include "RungeKuttaSolver.hpp"

#include <iostream>

double testFunction(double y, double t);

int main()
{
    FowardEulerSolver e1(&testFunction);

    e1.SetInitialValue(2);
    e1.SetStepSize(0.0001);
    e1.SetTimeInterval(0, 1);

    std::cout << "************Forward Euler*************\n";

    std::cout << "Sanity check, should be 3: " << e1.RightHandSide(5, 2) << "\n";

    std::cout << "Solve example with step size " << e1.GetStepSize() << " (target 3.5): " << e1.SolveEquation() << "\n";

    e1.SetStepSize(0.1);
    std::cout << "Solve example with step size " << e1.GetStepSize() << " (target 3.5): " << e1.SolveEquation() << "\n";

    RungeKuttaSolver rk1(&testFunction);

    rk1.SetInitialValue(2);
    rk1.SetStepSize(0.0001);
    rk1.SetTimeInterval(0, 1);

    std::cout << "************Runge-Kutta*************\n";

    std::cout << "Sanity check, should be 3: " << rk1.RightHandSide(5, 2) << "\n";

    std::cout << "Solve example with step size " << rk1.GetStepSize() << " (target 3.5): " << rk1.SolveEquation() << "\n";

    rk1.SetStepSize(0.1);
    std::cout << "Solve example with step size " << rk1.GetStepSize() << " (target 3.5): " << rk1.SolveEquation() << "\n";

    return 0;
}

double testFunction(double y, double t)
{
    return 1 + t;
}