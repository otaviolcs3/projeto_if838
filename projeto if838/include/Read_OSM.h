#ifndef READ_OSM_H
#define READ_OSM_H

#include "Graph.h"
#include "exception"
#include "readosm.h"
#include "PONInstance.h"

using std::exception;
using std::vector;

namespace read_osm
{
    Graph* read_osm_file(const char* file_name) throw (exception);
    static int handle_node(const void* user_data, const readosm_node* node);
    static int handle_way(const void* user_data, const readosm_way* way);
    static int handle_relation(const void* user_data, const readosm_relation* relation);

    class Invalid_suffix :public exception
    {
        public:
           virtual const char* what();
    };

    class File_not_found :public exception
    {
        public:
            virtual const char* what();
    };

    class Null_handle :public exception
    {
        public:
           virtual const char* what();
    };

    class Args
    {
        public:
            Args();
            Graph* graph;
    };
}


#endif // READ_OSM_H
