#include <iostream>
#include "../include/MyPair.h"
#include "../include/Graph.h"

using namespace std;

int* teste(int& a)
{
    return &a;
}


int main(int argc, char** argv)
{
    MyPair um(1,1),a(2,4),c(1,2),d(4,10);

    cout << (0.5*um*0.2 - a) << endl;

    int a1 =10;

    cout<< &a1 << ' ' << teste(a1) << endl;
    cout<< a1 << ' ' << *teste(a1) << endl;


    return 0;
}
