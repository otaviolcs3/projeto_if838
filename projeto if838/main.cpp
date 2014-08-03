#include <iostream>
#include <cstdio>

#include "../include/MyPair.h"
#include "../include/Graph.h"
#include "../include/OSM_read.h"

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

int main1(int argc, char** argv)
{
//    vector<pair<int,int> > my_vector;
//    my_vector.push_back(pair<int,int>(0,0));
//    my_vector.push_back(pair<int,int>(1,1));
//    my_vector.push_back(pair<int,int>(2,2));
//    my_vector.push_back(pair<int,int>(3,3));
//    my_vector.push_back(pair<int,int>(4,4));
//    my_vector.push_back(pair<int,int>(5,5));
//    my_vector.push_back(pair<int,int>(6,6));
//
//    make_heap(my_vector.begin(),my_vector.end(),comp);
//
//    my_vector[3].second = -1;
//    sobe(my_vector,3);
//
//
//    for(unsigned int i =0 ; i < my_vector.size();i++)
//    {
//        printf("(%d,%d) (%d)\r\n",my_vector[i].first,my_vector[i].second,i);
//    }

    Graph test;
    test.add_vertex( (new Vertex(Point(0,0),0)));
    test.add_vertex( (new Vertex(Point(1,0),1)));
    test.add_vertex( (new Vertex(Point(2,0),2)));
    test.add_vertex( (new Vertex(Point(3,0),3)));
    test.add_vertex( (new Vertex(Point(4,0),4)));
    test.add_vertex( (new Vertex(Point(5,0),5)));
    test.add_vertex( (new Vertex(Point(6,0),6)));
    test.add_vertex( (new Vertex(Point(7,0),7)));
    test.add_vertex( (new Vertex(Point(8,0),8)));
    test.add_vertex( (new Vertex(Point(9,0),9)));

    vector<Vertex*>& vertices = test.get_vertices();

    for(int i=0;i<10;i++)
    {
          cout << vertices[i]->get_coordinate() << endl;
    }

    cout << endl << endl << endl;

    vertices[0]->connect(*vertices[2],10);
    vertices[0]->connect(*vertices[3],3);
    vertices[0]->connect(*vertices[1],7);

    vertices[3]->connect(*vertices[2],2);
    //vertices[3]->update_cost(*vertices[2],4);

    vertices[1]->connect(*vertices[4],4);

    vertices[2]->connect(*vertices[4],5);

    for(unsigned int i=0;i<vertices.size();i++)
    {
        cout << "tem " << vertices[i]->get_edges().size() << " arestas" << endl;
        for(unsigned int j=0;j<vertices[i]->get_edges().size();j++)
        {
              cout << vertices[i]->get_coordinate() << " - " << (vertices[i]->get_edges()[j].first)->get_coordinate()
                << " : " <<vertices[i]->get_edges()[j].second << endl;
        }

        cout << endl;
    }

    cout << endl;
    cout << endl;

    Heap_node result = test.minimal_edges_between(vertices[0],vertices[4]);

    cout << "Result ("<< result.solution.size() <<") :" << result.cost  <<" INF:" << UINT_MAX << endl;

    for(unsigned int i =0 ; i<result.solution.size();i++)
    {
        cout << result.solution[i].first->get_coordinate() << endl;
    }

    cout << "Fim" << endl;

    return 0;
}


#include <cstdio>
#include <iostream>
#include "include/OSM_read.h"

#include <map>
#include <string>
#include <iostream>
#include <iterator>

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



    return 0;
}


