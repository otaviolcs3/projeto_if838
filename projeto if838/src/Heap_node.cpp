#include "../include/Heap_node.h"

Heap_node::Heap_node(Vertex* vertex,Cost cost)
{
    this->vertex=vertex;
    this->cost=cost;
}

Heap_node::Heap_node()
{
    this->cost=0;
}

Heap_node::~Heap_node()
{
    //dtor
}

Heap_node& Heap_node::operator=(const Heap_node& heap)
{
    this->vertex=heap.vertex;
    this->cost=heap.cost;
    this->solution=heap.solution;

    return (*this);
}
