#include "../include/MyPair.h"

MyPair::MyPair(double first,double second)
{
    this->first = first;
    this->second = second;
}

MyPair::MyPair()
{
    this->first = 0;
    this->second = 0;
}

MyPair::~MyPair()
{
    //dtor
}

MyPair MyPair::operator-(const MyPair& p)
{
    MyPair result;

    result.first = first - p.first;
    result.second = second - p.second;

    return result;
}

MyPair MyPair::operator+(const MyPair& p)
{
    MyPair result;

    result.first = first + p.first;
    result.second = second + p.second;

    return result;
}

MyPair MyPair::operator*(double cte)
{
    MyPair result;

    result.first = first * cte;
    result.second = second * cte;

    return result;
}

MyPair MyPair::operator/(double cte)
{
    MyPair result;

    result.first = first / cte;
    result.second = second / cte;

    return result;
}

MyPair operator*(double cte,const MyPair& par)
{
    MyPair result;

    result.first = par.first * cte;
    result.second = par.second * cte;

    return result;
}

std::ostream& operator<<(std::ostream& out, const MyPair& vec) // output
{
    out << "(" << vec.first << ", " << vec.second << ")";
    return out;
}
