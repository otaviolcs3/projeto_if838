#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <climits>
#include "Vertex.h"

using std::vector;
using std::pair;
using std::priority_queue;

class Graph
{
    public:
        Graph();
        ~Graph();
        Graph minimal_edges_between(Vertex&,Vertex&);
        void add_vertex(Vertex&);
        const vector<Vertex> get_vertices();

    private:
        vector<Vertex> vertices;
};

class MyHeap_comparison
{
    private:
        bool not_reverse;
    public:
        MyHeap_comparison(bool reverse);
        MyHeap_comparison();
        bool operator()(pair<Vertex*,Cost> left, pair<Vertex*,Cost> right);
};

typedef priority_queue<pair<Vertex*,Cost>,vector<pair<Vertex*,Cost> >,MyHeap_comparison> MyHeap;

#endif // GRAPH_H
