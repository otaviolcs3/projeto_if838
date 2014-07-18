#ifndef HEAP_NODE_H
#define HEAP_NODE_H

#include "Vertex.h"

using std::vector;
using std::pair;

class Heap_node
{
    public:
        Heap_node(Vertex*,Cost);
        Heap_node();
        virtual ~Heap_node();

    public:
        Heap_node& operator=(const Heap_node& heap);

        Vertex* vertex;
        Cost cost;
        vector <pair<Vertex*,Cost> > solution;
};

#endif // HEAP_NODE_H
