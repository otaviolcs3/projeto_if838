#include "../include/OSM_to_Graph.h"

#define DEGREE_TO_KM 1.0

double euclidian_distance(const Point& p1, const Point& p2)
{
	double x = p1.first - p2.first, y = p1.second - p2.second;
	return sqrt(x * x + y * y);
}

double cost_per_km()
{
    return 1.0;
}

Graph* OSM_to_Graph(OSM_control* controle)
{
    std::map<ID,Vertex*> vertices;
    Graph* graph = new Graph();

    for(size_t i =0; i < controle->nodes.size();i++)
    {
        auto node = controle->nodes[i];

        vertices[node->id]= new Vertex(Point(node->longitude*DEGREE_TO_KM,node->latitude*DEGREE_TO_KM),node->id);
    }
    for(size_t i =0; i < controle->ways.size();i++)
    {
        auto way = controle->ways[i];

        for(size_t i=0;i < way->node_refs.size()-1;i++)
        {
            vertices[way->node_refs[i]]->connect(*vertices[way->node_refs[i+1]],
                                        cost_per_km()*euclidian_distance(vertices[way->node_refs[i]]->get_coordinate(),
                                                                vertices[way->node_refs[i+1]]->get_coordinate()));
        }
    }
    for(auto i = vertices.begin();i != vertices.end();i++)
    {
        graph->add_vertex(i->second);
    }

    return graph;
}
