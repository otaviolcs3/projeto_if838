#include "../include/Graph.h"

bool MyHeap_comparison::operator()(pair<Vertex*,Cost> left, pair<Vertex*,Cost> right)
{
    bool comparison= (left.second < right.second);

    if(not_reverse) return comparison;
    else return (!comparison);
}

MyHeap_comparison::MyHeap_comparison():not_reverse(true)
{

}

MyHeap_comparison::MyHeap_comparison(bool reverse)
{
    not_reverse=!reverse;
}

Graph::Graph()
{
    //ctor
}

Graph::~Graph()
{
    //dtor
}

void Graph::add_vertex(Vertex& vert)
{
    vertices.push_back(vert);
}

const vector<Vertex> Graph::get_vertices()
{
    return vertices;
}

Graph Graph::minimal_edges_between(Vertex& origin,Vertex& destiny) // pode futuramente adicionar exceção de não encotrar o vertice
{
    vector<pair<Vertex*,Cost> > to_build_the_heap;

    unsigned int size_ = vertices.size();

    for(unsigned int i=0;i<size_;i++)
    {
        if(&vertices[i] != &origin) to_build_the_heap.push_back(pair<Vertex*,Cost>(&vertices[i],UINT_MAX));
        else to_build_the_heap.push_back(pair<Vertex*,Cost>(&vertices[i],0));
    }

    MyHeap heap(to_build_the_heap.begin(),to_build_the_heap.end());

    Graph result;


}

