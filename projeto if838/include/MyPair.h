#ifndef MYPAIR_H
#define MYPAIR_H

#include <utility>

class MyPair : public pair<double, double>
{
    public:
        MyPair();
        virtual ~MyPair();
        const MyPair& operator+(const MyPair&);
        const MyPair& operator*(double);
};

#endif // MYPAIR_H
