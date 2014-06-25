#ifndef OPTIMIZATIONPROBLEM_H
#define OPTIMIZATIONPROBLEM_H

#include "PONInstance.h"

typedef double (*Func2R) (const Point&);         //função do R^2 -> R
typedef double (*Func1R) (double); //R -> R
typedef Point Vector2;
typedef const Point& (*Grad)(const Vector2&);



class OptimizationProblem
{
    public:
        OptimizationProblem();
        virtual ~OptimizationProblem();

        enum StopCondition {};
        enum UnidimensionalMethod {};

        static double unidimensionalOptimization(double, Func1R);
        static const Point& gradientMethod(const Point&, Func2R, Grad);    //x0, f:R^2->R, grad
        //const Point& quasiNewtonMethod(Func2R, Grad/*, Hessian*/);

        static void setStopCondition(StopCondition);
        static void setUnidimensionalMethod(UnidimensionalMethod);

    protected:
    private:
        static double norm(const Vector2&);
        static const double smallValue = 1e-5;
        static StopCondition stopCondition;
        static UnidimensionalMethod unidimensionalMethod;
};

class OptimizationUtils
{
    private:
        static Point x0;
        static Func2R f2R;
        static Vector2 grad;

    public:
        static double f1R(double);
        static void setValues(const Point&, Func2R, const Vector2&);
};


#endif // OPTIMIZATIONPROBLEM_H

