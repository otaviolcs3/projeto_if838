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

void Graph::add_vertex(Vertex* vert)
{
    vertices.push_back(vert);
}

vector<Vertex*>& Graph::get_vertices()
{
    return vertices;
}

Heap_node Graph::minimal_edges_between(Vertex* origin,Vertex* destiny) // pode futuramente adicionar exce��o de n�o encotrar o vertice
{
    vector<Heap_node> the_heap;
    unsigned int size_ = vertices.size();
    Heap_node atual;
    Graph result;

    for(unsigned int i=0;i<size_;i++)
    {
        std::cout << "Puxei:" <<vertices[i]->get_coordinate() << " tem tantos arestas:" << vertices[i]->get_edges().size() << std::endl;

        if(vertices[i] != origin) the_heap.push_back(Heap_node(vertices[i],std::numeric_limits<double>::max()));
        else the_heap.push_back(Heap_node(vertices[i],0));
    }

    make_heap(the_heap.begin(),the_heap.end(),MyHeap_comparison<true>);

    while(!the_heap.empty())
    {
        if ((atual = the_heap[0]).vertex == destiny) break; // se for o destino sai

        pop_heap(the_heap.begin(),the_heap.end(),MyHeap_comparison<true>);
        the_heap.pop_back();

        std::cout << "Puxei:" <<atual.vertex->get_coordinate() << " Custo:" << atual.cost <<" tem tantos arestas:" << atual.vertex->get_edges().size() << std::endl;

        unsigned int pos;

        size_ = atual.vertex->get_edges().size();

        for(unsigned int i=0;i<size_;i++)
        {
            if(in_heap(the_heap,atual.vertex->get_edges()[i].first,pos))
            {
                if(atual.cost+atual.vertex->get_edges()[i].second < the_heap[pos].cost)
                {
                    the_heap[pos].cost = atual.cost+atual.vertex->get_edges()[i].second;
                    the_heap[pos].solution= atual.solution;
                    the_heap[pos].solution.push_back(pair<Vertex*,Cost>(atual.vertex->get_edges()[i].first,atual.vertex->get_edges()[i].second));
                    up_heap(the_heap,pos);
                }
            }
        }
    }

    return atual;
}







