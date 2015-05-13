#ifndef SUBMISSION_FOWARDEULERSOLVER_HPP_
#define SUBMISSION_FOWARDEULERSOLVER_HPP_

#include "AbstractOdeSolver.hpp"

class FowardEulerSolver : public AbstractOdeSolver {
	private:
		double (*right)(double y, double t);
	public:
		FowardEulerSolver(double (*f)(double y, double t));
		virtual double RightHandSide(double y, double t);
		virtual double SolveEquation();
};



#endif /* SUBMISSION_FOWARDEULERSOLVER_HPP_ */
