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
    edges.push_back(pair<Vertex*,unsigned int>(&vert,distance));
    vert.edges.push_back(pair<Vertex*,unsigned int>(this,distance));
}

const vector<pair<Vertex*,unsigned int> >& Vertex::getEdges()
{
    return edges;
}
