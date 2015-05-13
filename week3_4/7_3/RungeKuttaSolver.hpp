#ifndef SUBMISSION_RUNGEKUTTASOLVER_HPP_
#define SUBMISSION_RUNGEKUTTASOLVER_HPP_

#include "AbstractOdeSolver.hpp"

class RungeKuttaSolver : public AbstractOdeSolver {
	private:
		double (*right)(double y, double t);
	public:
		RungeKuttaSolver(double (*f)(double y, double t));
		virtual double RightHandSide(double y, double t);
		virtual double SolveEquation();
};



#endif /* SUBMISSION_RUNGEKUTTASOLVER_HPP_ */
