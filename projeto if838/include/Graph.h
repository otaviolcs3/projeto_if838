#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
//#include <queue>
#include <iterator>
#include <utility>
#include <climits>
#include <limits>

#include "Vertex.h"
#include "Heap_node.h"

using std::vector;
using std::pair;
//using std::priority_queue;
using std::make_heap;
using std::pop_heap;
using std::swap;

class Graph
{
    public:
        Graph();
        ~Graph();
        Heap_node minimal_edges_between(Vertex*,Vertex*);
        void add_vertex(Vertex*);
        vector<Vertex*>& get_vertices();

    private:
        vector<Vertex*> vertices;
};

bool MyHeap_comparison(Heap_node& left, Heap_node& right);
void up_heap(vector<Heap_node>& vec,unsigned int posicao);
bool in_heap(vector<Heap_node>& vec, Vertex* is_in,unsigned int& pos);


//typedef priority_queue<pair<Vertex*,Cost>,vector<pair<Vertex*,Cost> >,MyHeap_comparison> MyHeap;

#endif // GRAPH_H
