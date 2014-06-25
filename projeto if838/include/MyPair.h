#ifndef MYPAIR_H
#define MYPAIR_H

#include <utility>
#include <iostream>


class MyPair : public std::pair<double, double>
{
    public:
        MyPair();
        MyPair(double first,double second);
        ~MyPair();
        MyPair operator+(const MyPair&);
        MyPair operator-(const MyPair&);
        MyPair operator*(double);
        MyPair operator/(double);

    friend MyPair operator*(double ,const MyPair&);
    friend std::ostream& operator<<(std::ostream& out, const MyPair& vec); // output

};

#endif // MYPAIR_H
