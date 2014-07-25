#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <utility>
#include "MyPair.h"

using std::vector;
using std::pair;

typedef MyPair Point;
typedef unsigned int Cost;

class Vertex
{
    typedef pair<Vertex*,Cost> Edge;

    public:
        Vertex(Point); //so pra debug
        Vertex(Point,const long long id);
        Vertex();
        virtual ~Vertex();
        void connect(Vertex&,Cost);
        void update_cost(Vertex&,Cost);
        const vector<Edge>& get_edges();
        const Point& get_coordinate();
        bool operator==(Vertex&);

    private:
        vector<Edge> edges;
        Point coordinate;
        const long long id;

};

#endif // VERTEX_H
