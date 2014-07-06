#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <utility>
#include "MyPair.h"

using std::vector;
using std::pair;

typedef MyPair Point;

class Vertex
{
    typedef pair<Vertex*,unsigned int> Edge;

    public:
        Vertex();
        ~Vertex();
        void connect(Vertex&,unsigned int);
        const vector<Edge>& getEdges();

    private:
        vector<Edge> edges;
        //Point coordinate;

};

#endif // VERTEX_H
