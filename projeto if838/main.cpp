#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <iterator>

#include "../include/MyPair.h"
#include "../include/Graph.h"
#include "../include/OSM_read.h"
#include "../include/OSM_to_Graph.h"

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



int main2() {
  std::map<int,std::string> a_map;
  a_map[6]     = "Italian";
  a_map[1]    = "Chinese";
  a_map[4]   = "Japanese";
  a_map[3] = "German";
  a_map[5]     = "American";
  a_map[2]  = "French";


  for (auto it = a_map.begin(); it != a_map.end(); ++it) {
    std::cout << it->first << " : " << it->second << '\n';
  }

  return 0;
}

int main()
{
    //freopen("saida.txt","w",stdout);

    //printf("%g\n",std::numeric_limits<float>::max());
    //printf("%lg\n",std::numeric_limits<double>::max());
    //printf("%llg\n",std::numeric_limits<long double>::max());

    OSM_read parser(100000);
    OSM_control* controle = parser.run_parser("data/teste.osm");

    //controle->nodes[id]->print_node();
//    for(auto i =controle->nodes.begin(); i !=controle->nodes.end();i++)
//    {
//        i->second->print_node();
//        //printf("\n");
//    }

    for(size_t i =0; i < controle->nodes.size();i++)
    {
        controle->nodes[i]->print_node();
    }
    for(size_t i =0; i < controle->ways.size();i++)
        controle->ways[i]->print_way();
    for(size_t i =0; i < controle->relations.size();i++)
        controle->relations[i]->print_relation();

    auto grafo = OSM_to_Graph(controle);
    auto vertices = grafo->get_vertices();
    Vertex *a,*b;

    for(size_t i=0;i<vertices.size();i++)
    {
        if(vertices[i]->get_id()==4)
        {
            a =vertices[i];
        }
    }

    for(size_t i=0;i<vertices.size();i++)
    {
        if(vertices[i]->get_id()==2)
        {
            b =vertices[i];
        }
    }

    Heap_node result = grafo->minimal_edges_between(a,b);

    cout << "Result ("<< result.solution.size() <<") :" << result.cost << endl;

    for(unsigned int i =0 ; i<result.solution.size();i++)
    {
        cout << result.solution[i].first->get_id()<<" : "<<result.solution[i].second << endl;
    }

    cout << endl <<result.cost << endl;

    return 0;
}


