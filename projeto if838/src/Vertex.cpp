#include "../include/Vertex.h"

Vertex::Vertex(Point coordinate)
{
    this->coordinate=coordinate;
}

Vertex::~Vertex()
{
    //dtor
}

bool Vertex::operator==(Vertex& vert)
{
    if(coordinate == vert.coordinate) return true;
    else return false;
}

void Vertex::connect(Vertex& vert, Cost distance)
{
    edges.push_back(Vertex::Edge(&vert,distance));
    vert.edges.push_back(Vertex::Edge(this,distance));
}


/// duvida se uso ponteiro ou coordenada pra decidir se 2 vertices são iguais
void Vertex::update_cost(Vertex& vert, Cost new_distance) // pode futuramente adicionar exceção de não encotrar o vertice
{
    unsigned int size_ = edges.size();
    Vertex *opposite = NULL;

    for(unsigned int i = 0;i<size_;i++)
    {
        if(edges[i].first == &vert)
        {
            edges[i].second=new_distance;
            opposite = &vert;
            break;
        }
    }

    if(opposite!=NULL)
    {
        size_ = opposite->edges.size();

        for(unsigned int i = 0;i<size_;i++)
        {
            if(opposite->edges[i].first== this)
            {
                opposite->edges[i].second=new_distance;
                break;
            }
        }
    }
}

const vector<Vertex::Edge>& Vertex::get_edges()
{
    return edges;
}
