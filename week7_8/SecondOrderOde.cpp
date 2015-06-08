#include "SecondOrderOde.hpp"

SecondOrderOde::SecondOrderOde(double coeffUxx, double coeffUx,
                               double coeffU,
                               double (*righthandSide)(double),
                               double xMinimum, double xMaximum)
{
    mCoeffOfUxx = coeffUxx;
    mCoeffOfUx = coeffUx;
    mCoeffOfU = coeffU;
    mpRhsFunc = righthandSide;
    mXmin = xMinimum;
    mXmax = xMaximum;
}
