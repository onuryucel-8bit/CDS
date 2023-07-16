#ifndef CDS_GRAPH_LL_H
#define CDS_GRAPH_LL_H

#include"../CDS_LinkedList/CDS_LinkedList.h"
#include"../CDS_Array/CDS_DynamicArray.h"

#include<stdarg.h>
#include<stdlib.h>

//lil = (li)nked (l)ist
///LEARN: variant list

//---------GRAPH STRUCTURE---------
/*

    graph_lil ===> array ==> array->arrayHead[i].data ==>

    -->grap_interface_node => linkedlist

*/
typedef struct stdGraph_Node cdst_graph_interface_node;

struct stdGraph_Node{
    int node_name;
    cdst_linkedList_List* linked_list_connection;
};

typedef struct stdGraphAdjan cdst_graph_lil;

struct stdGraphAdjan{
    cdst_array* adjan_list;
};

cdst_graph_lil* CDS_graph_lil_init();

void CDS_graph_lil_addNode(cdst_graph_lil* graph,int data);

void CDS_graph_lil_connectNodes(cdst_graph_lil* graph,int source,unsigned int n, ...);

void CDS_graph_lil_destroy(cdst_graph_lil* graph);

#endif // CDS_GRAPH_H
