#include "../include/OSM_basic_classes.h"

OSM_member::OSM_member(OSM_MEMBER_TYPE member_type,long long int id,const char* role)
{
    this->role = new char[strlen(role)+1]; // preciso de mais um espaço pro '\0'
    strcpy(this->role,role);
    this->id=id;
    this->member_type=member_type;
}

OSM_member::~OSM_member()
{
    delete[] role;
}

//void OSM_tag::set(const char* key,const char* value)
//{
//    this->key = new char[strlen(key)+1]; // preciso de mais um espaço pro '\0'
//    this->value = new char[strlen(value)+1]; // preciso de mais um espaço pro '\0'
//    strcpy(this->key,key);
//    strcpy(this->value,value);
//}

OSM_tag::OSM_tag(const char* key,const char* value)
{
    this->key = new char[strlen(key)+1]; // preciso de mais um espaço pro '\0'
    this->value = new char[strlen(value)+1]; // preciso de mais um espaço pro '\0'
    strcpy(this->key,key);
    strcpy(this->value,value);
}

//OSM_tag::OSM_tag()
//{
//    this->key = NULL;
//    this->value = NULL;
//}

OSM_tag::~OSM_tag()
{
    if(key!=NULL) delete[] key;
    if(value!=NULL) delete[] value;
}

OSM_node::OSM_node()
{

}

OSM_node::~OSM_node()
{
    if(user!=NULL) delete[] user;
    if(timestamp!=NULL) delete[] timestamp;

    for(size_t i=0;i<tags.size();i++)
    {
        if(tags[i]!=NULL) delete tags[i];
    }
}

void OSM_node::print_node()
{
    printf("<node ");
    printf("id=%lld ",id);
    if(visible)
        printf("visible=true ");
    else
        printf("visible=false ");
    printf("version=%d ",version);
    printf("changeset=%lld ",changeset);
    printf("timestamp=%s ",timestamp);
    printf("user=%s ",user);
    printf("uid=%d ",uid);
    printf("lat=%.7lf ",latitude);
    printf("lon=%.7lf",longitude);
    if(tags.size() == 0)
        printf("/>\n");
    else
    {
        printf(">\n");
        for(size_t i =0;i<tags.size();i++)
            printf("<tag k=%s v=%s/>\n",tags[i]->key,tags[i]->value);
        printf("</node>\n");
    }
}

void OSM_node::set_timestamp(const char* timestamp)
{
    this->timestamp = new char[strlen(timestamp)+1]; // preciso de mais um espaço pro '\0'
    strcpy(this->timestamp,timestamp);
}

void OSM_node::set_user(const char* user)
{
    this->user = new char[strlen(user)+1]; // preciso de mais um espaço pro '\0'
    strcpy(this->user,user);
}

OSM_way::OSM_way()
{

}

OSM_way::~OSM_way()
{
    if(user!=NULL) delete[] user;
    if(timestamp!=NULL) delete[] timestamp;

    for(size_t i=0;i<tags.size();i++)
    {
        if(tags[i]!=NULL) delete tags[i];
    }
}

void OSM_way::print_way()
{
    printf("<way ");
    printf("id=%lld ",id);
    if(visible)
        printf("visible=true ");
    else
        printf("visible=false ");
    printf("version=%d ",version);
    printf("changeset=%lld ",changeset);
    printf("timestamp=%s ",timestamp);
    printf("user=%s ",user);
    printf("uid=%d ",uid);
    if(tags.size() == 0 && node_refs.size() == 0)
        printf("/>");
    else
    {
        printf(">\n");
        for(size_t i =0;i<node_refs.size();i++)
            printf("<nd ref=%lld/>\n",node_refs[i]);
        for(size_t i =0;i<tags.size();i++)
            printf("<tag k=%s v=%s/>\n",tags[i]->key,tags[i]->value);
        printf("</way>\n");
    }
}

void OSM_way::set_timestamp(const char* timestamp)
{
    this->timestamp = new char[strlen(timestamp)+1]; // preciso de mais um espaço pro '\0'
    strcpy(this->timestamp,timestamp);
}

void OSM_way::set_user(const char* user)
{
    this->user = new char[strlen(user)+1]; // preciso de mais um espaço pro '\0'
    strcpy(this->user,user);
}

OSM_relation::OSM_relation()
{

}

OSM_relation::~OSM_relation()
{
    if(user!=NULL) delete[] user;
    if(timestamp!=NULL) delete[] timestamp;

    for(size_t i=0;i<tags.size();i++)
    {
        if(tags[i]!=NULL) delete tags[i];
    }

    for(size_t i=0;i<members.size();i++)
    {
        if(members[i]!=NULL) delete members[i];
    }
}

void OSM_relation::set_timestamp(const char* timestamp)
{
    this->timestamp = new char[strlen(timestamp)+1]; // preciso de mais um espaço pro '\0'
    strcpy(this->timestamp,timestamp);
}

void OSM_relation::set_user(const char* user)
{
    this->user = new char[strlen(user)+1]; // preciso de mais um espaço pro '\0'
    strcpy(this->user,user);
}

void OSM_relation::print_relation()
{
    printf("<relation ");
    printf("id=%lld ",id);
    if(visible)
        printf("visible=true ");
    else
        printf("visible=false ");
    printf("version=%d ",version);
    printf("changeset=%lld ",changeset);
    printf("timestamp=%s ",timestamp);
    printf("user=%s ",user);
    printf("uid=%d ",uid);
    if(tags.size() == 0 && members.size() == 0)
        printf("/>");
    else
    {
        printf(">\n");
        for(size_t i =0;i<members.size();i++)
        {
            if(members[i]->member_type == OSM_MEMBER_NODE) printf("<member type=node ref=%lld role=%s/>\n",members[i]->id,members[i]->role);
            else if(members[i]->member_type == OSM_MEMBER_WAY) printf("<member type=way ref=%lld role=%s/>\n",members[i]->id,members[i]->role);
            else  printf("<member type=relation ref=%lld role=%s/>\n",members[i]->id,members[i]->role);
        }

        for(size_t i =0;i<tags.size();i++)
            printf("<tag k=%s v=%s/>\n",tags[i]->key,tags[i]->value);
        printf("</relation>\n");
    }

}
