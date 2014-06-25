#ifndef OPTIMIZATIONPROBLEM_H
#define OPTIMIZATIONPROBLEM_H

#include "PONInstance.h"

typedef Dist Func2R;         //função do R^2 -> R
typedef double (*Func1R) (double); //R -> R
typedef Point Vector2;
typedef const Point& (*Grad)(Func2R, const Vector2&);

class OptimizationProblem
{
    public:
        OptimizationProblem();
        virtual ~OptimizationProblem();

        enum UnidimensionalMethod {a_123=0};
        enum StopCondition {b_123=0};

        static double unidimensionalOptimization(double, Func1R);
        static const Point& gradientMethod(const Point&, Func2R, Grad);    //x0, f:R^2->R, grad
        //const Point& quasiNewtonMethod(Func2R, Grad/*, Hessian*/);

    protected:
    private:
        static double norm(const Vector2&);
        static const double smallValue = 1e-5;
};



#endif // OPTIMIZATIONPROBLEM_H

