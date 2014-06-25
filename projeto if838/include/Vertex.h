#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include "MyPair.h"
#include <utility>

typedef MyPair Point;

using std::vector;
using std::pair;

class Vertex
{
    public:
        Vertex();
        ~Vertex();
        void connect(Vertex&,unsigned int);

    private:
        const vector<pair<Vertex*,unsigned int> >& getEdges();

        vector<pair<Vertex*,unsigned int> > edges;
        //Point coordinate;

};

#endif // VERTEX_H
