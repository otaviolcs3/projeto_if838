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
        Vertex();
        ~Vertex();
        void connect(Vertex&,Cost);
        void update_cost(Vertex&,Cost);
        const vector<Edge>& getEdges();
        bool operator==(Vertex&);

    private:
        vector<Edge> edges;
        Point coordinate;

};

#endif // VERTEX_H
