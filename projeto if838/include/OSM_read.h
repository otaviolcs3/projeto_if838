#ifndef OSM_READ_H
#define OSM_READ_H

#include "OSM_basic_classes.h"
#include <expat.h>
#include <cstring>
#include <exception>
#include <vector>
#include <map>

typedef long long int ID;

class OSM_control
{
    public:
        OSM_control();
        ~OSM_control();

        bool node_inside;
        bool way_inside;
        bool relation_inside;

        //long long int actual_node_id;

        //std::map<ID,OSM_node*>nodes;
        std::vector<OSM_node*>nodes;
        std::vector<OSM_way*>ways;
        std::vector<OSM_relation*> relations;
};

class OSM_read
{
    public:
        OSM_read(size_t buffer_size);
        ~OSM_read();
        OSM_control* run_parser(char* file_name) throw (std::exception);

    private:
        static OSM_node* OSM_node_start_handle(const char** attribute);
        static OSM_way* OSM_way_start_handle(const char** attribute);
        static OSM_relation* OSM_relation_start_handle(const char** attribute);
        static void start_handle(void *data_handle, const char *element, const char **attribute);
        static void end_handle(void *data_handle, const char *element);
        static void data_handle(void *data_handle, const char *content, int length);

    private:
        size_t buffer_size;
        char* buffer;

    friend int parse_xml2(char *buff, size_t buff_size);
};

#endif // OSM_READ_H
