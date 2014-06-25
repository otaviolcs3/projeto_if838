#include "../include/OptimizationProblem.h"

OptimizationProblem::StopCondition OptimizationProblem::stopCondition;
OptimizationProblem::UnidimensionalMethod OptimizationProblem::unidimensionalMethod;

OptimizationProblem::OptimizationProblem()
{
    //ctor
}

OptimizationProblem::~OptimizationProblem()
{
    //dtor
}

double OptimizationUtils::f1R(double lambda)
{
    return f2R(x0 + lambda * grad);
}

void OptimizationUtils::setValues(const Point& _x0, Func2R _f2R, const Vector2& _grad)
{
    x0 = _x0; f2R = _f2R; grad = _grad;
}

Point OptimizationUtils::x0;
Func2R OptimizationUtils::f2R;
Vector2 OptimizationUtils::grad;

double OptimizationProblem::unidimensionalOptimization(double x0, Func1R f)
{

}

double norm(const Vector2& v)
{
    double x = v.first, y = v.second;
    return sqrt(x * x + y * y);
}

const Point& OptimizationProblem::gradientMethod(const Point& _x0, Func2R f, Grad g)
{
    Point x0 = _x0;
    do
    {
        Vector2 grad = (-1) * g(x0);
        OptimizationUtils::setValues(x0, f, grad);

        double lambda = unidimensionalOptimization(0, OptimizationUtils::f1R);
        x0 = x0 + lambda * grad;
    }while(true);

    return *(new MyPair(0,0));
}
