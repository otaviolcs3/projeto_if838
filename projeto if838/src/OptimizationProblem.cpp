#include "OptimizationProblem.h"

OptimizationProblem::OptimizationProblem()
{
    //ctor
}

OptimizationProblem::~OptimizationProblem()
{
    //dtor
}

static const Point& OptimizationProblem::gradientMethod(const Point& x0, Func f, Grad g)
{
    double uni_f(double lambda)
    {
        return f(x0 + lambda * grad);
    }
}
