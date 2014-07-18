#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
//#include <queue>
#include <iterator>
#include <utility>
#include <climits>

#include "Vertex.h"
#include "Heap_node.h"

using std::vector;
using std::pair;
//using std::priority_queue;
using std::make_heap;
using std::pop_heap;
using std::swap;
using std::random_access_iterator_tag;

class Graph
{
    public:
        Graph();
        ~Graph();
        Graph minimal_edges_between(Vertex&,Vertex&);
        void add_vertex(Vertex&);
        const vector<Vertex>& get_vertices();

    private:
        vector<Vertex> vertices;
};

template <bool min>
bool MyHeap_comparison(pair<Vertex*,Cost>& left, pair<Vertex*,Cost>& right);
void up_heap(vector<pair<Vertex*,Cost> >& vec,unsigned int posicao);


//typedef priority_queue<pair<Vertex*,Cost>,vector<pair<Vertex*,Cost> >,MyHeap_comparison> MyHeap;

#endif // GRAPH_H
