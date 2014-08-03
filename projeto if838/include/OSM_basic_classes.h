#ifndef OSM_BASIC_CLASSES_H
#define OSM_BASIC_CLASSES_H

#include <cstdio>
#include <cstring>
#include <vector>

typedef long long int ID;

enum OSM_MEMBER_TYPE{OSM_MEMBER_NODE=0,OSM_MEMBER_WAY,OSM_MEMBER_RELATION};


/**std::vector<OSM_tag*> tags; tem que ser de ponteiro pq senão da merda. Na hora de copiar da pilha, ele copia
o mesmo endereço, dai termina sendo destruido 2x uma na pilha e outra quando for destruir a estrutura**/

class OSM_member
{
    public:
        OSM_member(OSM_MEMBER_TYPE member_type,long long int id,const char* role);
        ~OSM_member();

    public:
        OSM_MEMBER_TYPE member_type;//can be one of: OSM_MEMBER_NODE, OSM_MEMBER_WAY or OSM_MEMBER_RELATION
        long long int id;//ID-value identifying the referenced object.
        char* role;//intended role for this reference
};

class OSM_tag
{
    public:
       // OSM_tag();
        OSM_tag(const char* key,const char* value);
        ~OSM_tag();
        //void set(const char* key,const char* value);

    public:
        char* key;
        char* value;
};

class OSM_node
{
    public:
        OSM_node();
        ~OSM_node();
        void set_user(const char*);
        void set_timestamp(const char*);
        void print_node();

    public:
        long long int id;   //NODE-ID (expected to be a unique value)
        double latitude; //geographic latitude
        double longitude; //geographic longitude
        int version;     //object version
        long long int changeset;  //ChangeSet ID.
        char* user; //name of the User defining this NODE
        int uid;//corresponding numeric UserID
        char* timestamp; //when this NODE was defined
        bool visible;
        std::vector<OSM_tag*> tags; //array of TAG objects (may be empty)
};

class OSM_way
{
    public:
        OSM_way();
        ~OSM_way();
        void print_way();
        void set_user(const char*);
        void set_timestamp(const char*);

    public:
        long long int id;//WAY-ID (expected to be a unique value)
        int version;//object version
        long long int changeset;//ChangeSet ID.
        char* user;//name of the User defining this WAY
        int uid;//corresponding numeric UserID
        char* timestamp;//when this WAY was defined
        bool visible;
        std::vector<ID> node_refs;//array of NODE-IDs (may be empty)
        std::vector<OSM_tag*> tags; //array of TAG objects (may be empty)

};

class OSM_relation
{
    public:
        OSM_relation();
        ~OSM_relation();
        void set_user(const char*);
        void set_timestamp(const char*);
        void print_relation();

    public:
        long long int id;//RELATION-ID (expected to be a unique value)
        int version;//object version
        long long int changeset;//ChangeSet ID.
        char* user;//name of the User defining this RELATION
        int uid;//corresponding numeric UserID
        char* timestamp;//when this RELATION was defined
        bool visible;
        std::vector<OSM_member*> members; //array of members objects (may be empty)
        std::vector<OSM_tag*> tags; //array of TAG objects (may be empty)
};

#endif // OSM_BASIC_CLASSES_H
