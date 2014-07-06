#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Vertex.h"

using std::vector;

class Graph
{
    public:
        Graph();
        ~Graph();
    private:
        vector<Vertex> vertices;
};

#endif // GRAPH_H
