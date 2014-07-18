#include "../include/Graph.h"

template <bool min>
bool MyHeap_comparison(Heap_node& left, Heap_node& right)
{
    bool comparison= (left.cost > right.cost); // (<) vira heap de maximo
                                                   // (>) vira heap de minimo

    if(min) return comparison;
    else return (!comparison);
}

void up_heap(vector<Heap_node>& vec,unsigned int posicao)
{
    if(posicao != 0)
    {
        unsigned int pai = (posicao - 1)/2;

        if(vec[posicao].cost < vec[pai].cost)
        {
            swap<Heap_node>(vec[posicao],vec[pai]);
            up_heap(vec,pai);
        }
    }
}

bool in_heap(vector<Heap_node>& vec, Vertex* is_in,unsigned int& pos)
{
    unsigned int size_ = vec.size();
    for(unsigned int i=0;i<size_;i++)
    {
        if(vec[i].vertex == is_in)
        {
            pos=i;
            return true;
        }
    }

    return false;
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

const vector<Vertex>& Graph::get_vertices()
{
    return vertices;
}

Graph Graph::minimal_edges_between(Vertex& origin,Vertex& destiny) // pode futuramente adicionar exceção de não encotrar o vertice
{
    vector<Heap_node> the_heap;
    unsigned int size_ = vertices.size();
    Heap_node atual;
    Graph result;

    for(unsigned int i=0;i<size_;i++)
    {
        if(&vertices[i] != &origin) the_heap.push_back(Heap_node(&vertices[i],UINT_MAX));
        else the_heap.push_back(Heap_node(&vertices[i],0));
    }

    make_heap(the_heap.begin(),the_heap.end(),MyHeap_comparison<true>);

    while((atual = the_heap[0]).vertex!= &destiny)
    {
        pop_heap(the_heap.begin(),the_heap.end());
        the_heap.pop_back();

        unsigned int pos;

        size_ = atual.vertex->get_edges().size();

        for(unsigned int i=0;i<size_;i++)
        {
            if(in_heap(the_heap,atual.vertex->get_edges()[i].first,pos))
            {
                if(atual.cost+atual.vertex->get_edges()[i].second < the_heap[pos].cost)
                {
                    the_heap[pos].cost = atual.cost+atual.vertex->get_edges()[i].second;
                    up_heap(the_heap,pos);
                }
            }
        }
    }


}




