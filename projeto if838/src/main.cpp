#include <iostream>
#include <cstdio>
#include "readosm.h"

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

int main_(int argc, char** argv)
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
    test.add_vertex( *(new Vertex(Point(0,0))));
    test.add_vertex( *(new Vertex(Point(1,0))));
    test.add_vertex( *(new Vertex(Point(2,0))));
    test.add_vertex( *(new Vertex(Point(3,0))));
    test.add_vertex( *(new Vertex(Point(4,0))));
    test.add_vertex( *(new Vertex(Point(5,0))));
    test.add_vertex( *(new Vertex(Point(6,0))));
    test.add_vertex( *(new Vertex(Point(7,0))));
    test.add_vertex( *(new Vertex(Point(8,0))));
    test.add_vertex( *(new Vertex(Point(9,0))));

    vector<Vertex>& vertices = test.get_vertices();

    for(int i=0;i<10;i++)
    {
          cout << vertices[i].get_coordinate() << endl;
    }

    cout << endl << endl << endl;

    vertices[0].connect(vertices[2],10);
    vertices[0].connect(vertices[3],3);
    vertices[0].connect(vertices[1],7);

    vertices[3].connect(vertices[2],2);

    vertices[1].connect(vertices[4],4);

    vertices[2].connect(vertices[4],5);

    for(unsigned int i=0;i<vertices.size();i++)
    {
        cout << "tem " << vertices[i].get_edges().size() << " arestas" << endl;
        for(unsigned int j=0;j<vertices[i].get_edges().size();j++)
        {
              cout << vertices[i].get_coordinate() << " - " << (vertices[i].get_edges()[j].first)->get_coordinate()
                << " : " <<vertices[i].get_edges()[j].second << endl;
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

static int print_node (const void *user_data, const readosm_node * node)
{
    printf("node: %lf %lf\n",node->latitude,node->longitude);

    return READOSM_OK;
}

static int print_way (const void *user_data, const readosm_way * way)
{
    return READOSM_OK;
}

static int print_relation (const void *user_data, const readosm_relation * relation)
{
    return READOSM_OK;
}

int main (int argc, char *argv[])
{
    const void *osm_handle;
    int ret;

    ret = readosm_open ("map/map.osm", &osm_handle);

    if (ret != READOSM_OK)
    {
        fprintf (stderr, "OPEN error: %d\n", ret);
        goto stop;
    }

    ret = readosm_parse (osm_handle,NULL,print_node, print_way,print_relation);

    if (ret != READOSM_OK)
    {
        fprintf (stderr, "PARSE error: %d\n", ret);
        goto stop;
    }

    fprintf (stderr, "Ok, OSM input file successfully parsed\n");

stop:
    readosm_close (osm_handle);
    return 0;
}


