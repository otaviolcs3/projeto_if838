#include "../include/Read_OSM.h"

using namespace read_osm;

Args::Args()
{
    graph = new Graph();
}


const char* Invalid_suffix::what()
{
    return "not .osm or .pbf suffix";
}

const char* File_not_found::what()
{
    return ".osm or .pbf file does not exist or is not accessible for reading";
}

const char* Null_handle::what()
{
    return "Null OSM_handle argument";
}

static int read_osm::handle_node (const void *user_data, const readosm_node* node)
{
    Args* args = (Args*)user_data;
    //                                                X              Y
    args->graph->add_vertex(  *(new Vertex(Point(node->longitude,node->latitude),node->id)));

    return READOSM_OK;
}

static int read_osm::handle_way (const void *user_data, const readosm_way* way)
{
    Args* args = (Args*)user_data;

    const long long* ids = way->node_refs;
    unsigned int size = way->node_ref_count;




    return READOSM_OK;
}

static int read_osm::handle_relation (const void *user_data, const readosm_relation* relation)
{
    Args* args = (Args*)user_data;

    return READOSM_OK;
}

Graph* read_osm::read_osm_file(const char* file_name) throw (exception)
{
    const void *osm_handle;

    int ret = readosm_open ("map/map.osm", &osm_handle);

    if(ret==READOSM_INVALID_SUFFIX)
    {
        throw Invalid_suffix();
    }
    else if(ret == READOSM_FILE_NOT_FOUND)
    {
        throw File_not_found();
    }
    else if(ret == READOSM_NULL_HANDLE)
    {
        throw Null_handle();
    }

    Args* args= new Args();

    ret = readosm_parse (osm_handle,(void*) args,read_osm::handle_node,read_osm::handle_way,read_osm::handle_relation);

    /**FAZER AS EXCEPTIONS DO readosm_parser() DEPOIS**/


}
