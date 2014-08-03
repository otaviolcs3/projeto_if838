#include "../include/OSM_read.h"

OSM_control::OSM_control()
{
    node_inside=way_inside=relation_inside=false;
    //actual_node_id=0;
}

OSM_control::~OSM_control()
{
    for(size_t i =0; i<nodes.size(); i++)
    {
        delete nodes[i];
    }
    for(size_t i =0; i<ways.size(); i++)
    {
        delete ways[i];
    }
    for(size_t i =0; i<relations.size(); i++)
    {
        delete relations[i];
    }
}

OSM_read::OSM_read(size_t buffer_size)
{
    this->buffer_size=buffer_size;

    try
    {
        buffer = new char[buffer_size];
    }
    catch(std::exception &e)
    {
        e.what(); ///tratar
        exit(1);
    }
}

OSM_read::~OSM_read()
{
    delete[] buffer;
}

OSM_node* OSM_read::OSM_node_start_handle(const char** attribute)
{
    OSM_node* node = new OSM_node();
    long long int temp_int;
    double temp_double;

    for (int i = 0; attribute[i]!=NULL; i += 2)
    {
        if(strcmp(attribute[i],"id")==0)
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            node->id=temp_int;
        }
        else if(strcmp(attribute[i],"visible")==0)
        {
            if(strcmp(attribute[i+1],"true")==0)
            {
                node->visible=true;
            }
            else
            {
                node->visible=false;
            }
        }
        else if(strcmp(attribute[i],"version")==0)
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            node->version=temp_int;
        }
        else if(strcmp(attribute[i],"changeset")==0)
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            node->changeset=temp_int;
        }
        else if(strcmp(attribute[i],"timestamp")==0)
        {
            node->set_timestamp(attribute[i+1]);
        }
        else if(strcmp(attribute[i],"user")==0)
        {
            node->set_user(attribute[i+1]);
        }
        else if(strcmp(attribute[i],"uid")==0)
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            node->uid=temp_int;
        }
        else if(strcmp(attribute[i],"lat")==0)
        {
            sscanf(attribute[i+1],"%lf",&temp_double);
            node->latitude=temp_double;
        }
        else if(strcmp(attribute[i],"lon")==0)
        {
            sscanf(attribute[i+1],"%lf",&temp_double);
            node->longitude=temp_double;
        }
        else
        {
            ///tratar
        }
    }

    return node;
}

OSM_way* OSM_read::OSM_way_start_handle(const char** attribute)
{
    OSM_way* way = new OSM_way();
    long long int temp_int;

    for (int i = 0; attribute[i]!=NULL; i += 2)
    {
        if(strcmp(attribute[i],"id")==0)
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            way->id=temp_int;
        }
        else if(strcmp(attribute[i],"visible")==0)
        {
            if(strcmp(attribute[i+1],"true")==0)
            {
                way->visible=true;
            }
            else
            {
                way->visible=false;
            }
        }
        else if(strcmp(attribute[i],"version")==0)
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            way->version=temp_int;
        }
        else if(strcmp(attribute[i],"changeset")==0)
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            way->changeset=temp_int;
        }
        else if(strcmp(attribute[i],"timestamp")==0)
        {
            way->set_timestamp(attribute[i+1]);
        }
        else if(strcmp(attribute[i],"user")==0)
        {
            way->set_user(attribute[i+1]);
        }
        else if(strcmp(attribute[i],"uid")==0)
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            way->uid=temp_int;
        }
        else
        {
            ///tratar
        }
    }

    return way;
}

OSM_relation* OSM_read::OSM_relation_start_handle(const char** attribute)
{
    OSM_relation* relation = new OSM_relation();
    long long int temp_int;

    for (int i = 0; attribute[i]!=NULL; i += 2)
    {
        if(!strcmp(attribute[i],"id"))
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            relation->id=temp_int;
        }
        else if(!strcmp(attribute[i],"visible"))
        {
            if(!strcmp(attribute[i+1],"true"))
            {
                relation->visible=true;
            }
            else
            {
                relation->visible=false;
            }
        }
        else if(!strcmp(attribute[i],"version"))
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            relation->version=temp_int;
        }
        else if(!strcmp(attribute[i],"changeset"))
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            relation->changeset=temp_int;
        }
        else if(!strcmp(attribute[i],"timestamp"))
        {
            relation->set_user(attribute[i+1]);
        }
        else if(!strcmp(attribute[i],"user"))
        {
            relation->set_timestamp(attribute[i+1]);
        }
        else if(!strcmp(attribute[i],"uid"))
        {
            sscanf(attribute[i+1],"%lld",&temp_int);
            relation->uid=temp_int;
        }
        else
        {
            ///tratar
        }
    }

    return relation;
}

void OSM_read::start_handle(void *data_handle, const char *element, const char **attribute)
{
    OSM_control* control = (OSM_control*)data_handle;

    if(!strcmp(element,"node"))
    {
        control->node_inside = true;
        //OSM_node* returned_node = OSM_node_start_handle(attribute);
        //control->nodes[returned_node->id]=returned_node;
        //control->actual_node_id=returned_node->id;

        OSM_node* returned_node = OSM_node_start_handle(attribute);
        control->nodes.push_back(returned_node);
    }
    else if(!strcmp(element,"way"))
    {
        control->way_inside = true;
        OSM_way* returned_way = OSM_way_start_handle(attribute);
        control->ways.push_back(returned_way);
    }
    else if(!strcmp(element,"nd"))
    {
        if(control->way_inside)
        {
            if(!strcmp(attribute[0],"ref"))
            {
                long long int id_reference;
                sscanf(attribute[1],"%lld",&id_reference);
                control->ways[control->ways.size()-1]->node_refs.push_back(id_reference);
            }
            else
            {
                ///tratar
            }
        }
        else
        {
            ///tratar
        }
    }
    else if(!strcmp(element,"relation"))
    {
        control->relation_inside = true;
        OSM_relation* returned_way = OSM_relation_start_handle(attribute);
        control->relations.push_back(returned_way);
    }
    else if(!strcmp(element,"tag"))
    {
        if(control->node_inside)
        {
            //control->nodes[control->actual_node_id]->tags.push_back(new OSM_tag(attribute[1],attribute[3]));
            control->nodes[control->nodes.size()-1]->tags.push_back(new OSM_tag(attribute[1],attribute[3]));
        }
        else if(control->way_inside)
        {
            control->ways[control->ways.size()-1]->tags.push_back(new OSM_tag(attribute[1],attribute[3]));
        }
        else if(control->relation_inside)
        {
            control->relations[control->relations.size()-1]->tags.push_back(new OSM_tag(attribute[1],attribute[3]));
        }
        else
        {
            ///tratar
        }
    }
    else if(!strcmp(element,"member"))
    {
        if(control->relation_inside)
        {
            OSM_MEMBER_TYPE type;
            long long int ref_;

            if(!strcmp(attribute[1],"way"))
            {
                type = OSM_MEMBER_WAY;
            }
            else if(!strcmp(attribute[1],"node"))
            {
                type = OSM_MEMBER_NODE;
            }
            else if(!strcmp(attribute[1],"relation"))
            {
                type = OSM_MEMBER_RELATION;
            }
            else
            {
                ///tratar
            }

            sscanf(attribute[3],"%lld",&ref_);

            control->relations[control->relations.size()-1]->members.push_back(new OSM_member(type,ref_,attribute[5]));
        }
        else
        {
            ///tratar
        }
    }
    else if(!strcmp(element,"osm"))
    {

    }
    else
    {
        ///tratar
    }
}

void OSM_read::end_handle(void *data_handle, const char *element)
{
    OSM_control* control = (OSM_control*)data_handle;

    if(!strcmp(element,"node"))
    {
        control->node_inside = false;
    }
    else if(!strcmp(element,"way"))
    {
        control->way_inside = false;
    }
    else if(!strcmp(element,"relation"))
    {
        control->relation_inside = false;
    }
    else if(!strcmp(element,"tag"))
    {

    }
    else if(!strcmp(element,"member"))
    {

    }
    else if(!strcmp(element,"osm"))
    {

    }
    else
    {
        ///tratar
    }
}

void OSM_read::data_handle(void *data_handle, const char *content, int length)
{

}

OSM_control* OSM_read::run_parser(char* file_name) throw (std::exception)
{
    FILE* input = fopen(file_name,"r");

    if(input == NULL)
    {
        ///tratar
    }

    fseek(input, 0, SEEK_END);
    size_t file_size =ftell(input);
    fseek(input, 0, SEEK_SET);
    memset(buffer, 0, buffer_size);

    OSM_control* controle = new OSM_control();
    XML_Parser parser = XML_ParserCreate(NULL);
    XML_SetUserData(parser,(void*) controle);
    XML_SetElementHandler(parser, OSM_read::start_handle, OSM_read::end_handle);
    //XML_SetCharacterDataHandler(parser,OSM_read::data_handle);

    for(size_t already_read = 0,read; already_read<file_size;)
    {
        int is_end = XML_FALSE;

        read=fread(buffer, sizeof(char), buffer_size, input);
        already_read+=read;

        if(already_read==file_size)
        {
           is_end = XML_TRUE;
        }

        if (XML_Parse(parser, buffer, read, is_end) == XML_STATUS_ERROR)
        {
            printf("XML-Error(%d): %s\n",XML_GetErrorCode(parser), XML_ErrorString(XML_GetErrorCode(parser))); ///tratar
        }
    }

    fclose(input);
    XML_ParserFree(parser);

    return controle;
}

