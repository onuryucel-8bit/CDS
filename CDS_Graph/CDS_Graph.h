#ifndef CDS_GRAPH_LL_H
#define CDS_GRAPH_LL_H

#include"../CDS_LinkedList/CDS_LinkedList.h"
#include"../CDS_Array/CDS_DynamicArray.h"

#include<stdarg.h>
#include<stdlib.h>

//lil = (li)nked (l)ist
///LEARN: variant list

typedef struct stdGraphAdjan cdst_graph_lil;

struct stdGraphAdjan{
    cdst_array* adjan_list;
};

//cdst_graph_lil* CDS_graph_lil_init();

void CDS_graph_lil_addNode(cdst_graph_lil* graph,int data);

void CDS_graph_lil_destroy(cdst_graph_lil* graph);

#endif // CDS_GRAPH_H
