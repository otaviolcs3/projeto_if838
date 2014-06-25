#include "../include/OptimizationProblem.h"

OptimizationProblem::OptimizationProblem()
{
    //ctor
}

OptimizationProblem::~OptimizationProblem()
{
    //dtor
}

class OptimizationUtils
{
    public:
        static Point& x0;
        static Func2R f2R;
        static Vector2 grad;

        static double f1R(double lambda)
        {
            return f2R(x0 + lambda * grad);
        }

        static void setValues(const Point& _x0, Func2R _f2R, const Vector2& _grad)
        {
            x0 = _x0; f2R = _f2R; grad = _grad;
        }
};

const Point& OptimizationProblem::gradientMethod(const Point& x0, Func2R f, Grad g)
{

    return *(new MyPair(0,0));
}

//C:\Users\mfrr\projeto_if838\projeto if838\src\OptimizationProblem.cpp|20|error: local class 'class OptimizationProblem::gradientMethod(const Point&, double (*)(const Point&, const Point&), const Point& (*)(double (*)(const Point&, const Point&), const Vector2&))::Temp' shall not have static data member 'Point& OptimizationProblem::gradientMethod(const Point&, double (*)(const Point&, const Point&), const Point& (*)(double (*)(const Point&, const Point&), const Vector2&))::Temp::x0'|
