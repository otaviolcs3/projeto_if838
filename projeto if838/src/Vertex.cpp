#include "../include/Vertex.h"

Vertex::Vertex()
{
    //ctor
}

Vertex::~Vertex()
{
    //dtor
}

void Vertex::connect(Vertex& vert, unsigned int distance)
{
    edges.push_back(Vertex::Edge(&vert,distance));
    vert.edges.push_back(Vertex::Edge(this,distance));
}

const vector<Vertex::Edge>& Vertex::getEdges()
{
    return edges;
}
