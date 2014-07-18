#include <iostream>
#include <cstdio>
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

void sobe(vector<pair<int,int> >& vec,unsigned int posicao)
{
    if(posicao != 0)
    {
        unsigned int pai = (posicao - 1)/2;

        if(vec[posicao].second < vec[pai].second)
        {
            swap<pair<int,int> >(vec[posicao],vec[pai]);
            sobe(vec,pai);
        }
    }
}

bool comp(pair<int,int>&left,pair<int,int>&right)
{
    if(left.second>right.second) return true;
    else return false;
}



int main(int argc, char** argv)
{
    vector<pair<int,int>> my_vector;
    my_vector.push_back(pair<int,int>(0,0));
    my_vector.push_back(pair<int,int>(1,1));
    my_vector.push_back(pair<int,int>(2,2));
    my_vector.push_back(pair<int,int>(3,3));
    my_vector.push_back(pair<int,int>(4,4));
    my_vector.push_back(pair<int,int>(5,5));
    my_vector.push_back(pair<int,int>(6,6));

    make_heap(my_vector.begin(),my_vector.end(),comp);

    my_vector[3].second = -1;
    sobe(my_vector,3);


    for(unsigned int i =0 ; i < my_vector.size();i++)
    {
        printf("(%d,%d) (%d)\r\n",my_vector[i].first,my_vector[i].second,i);
    }

    return 0;
}
