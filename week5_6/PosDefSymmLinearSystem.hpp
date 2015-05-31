#ifndef POSDEFSYMMLINEARSYSTEM
#define POSDEFSYMMLINEARSYSTEM
#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"

class PosDefSymmLinearSystem : public LinearSystem
{
private:
	double epsilon;
public:
	PosDefSymmLinearSystem(const Matrix& A, const Vector& b, const double epsilon);
	virtual Vector Solve();
};


#endif