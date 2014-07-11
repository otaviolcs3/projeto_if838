#include <iostream>
#include "../include/MyPair.h"
#include "../include/Graph.h"

using namespace std;

class MyInt
{
    public:
        vector<int> a;
};

class Teste
{
    public:
        vector<MyInt> vetor;
        void add(MyInt& inteiro)
        {
            vetor.push_back(inteiro);
        }
};



int main(int argc, char** argv)
{
    MyInt *variavel = new MyInt();
    Teste teste ;

    variavel->a.push_back(18000);

    teste.add(*variavel);

    variavel->a[0]=1450;

    cout << teste.vetor[0].a[0] << endl;


    return 0;
}
