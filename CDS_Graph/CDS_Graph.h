#ifndef CDS_GRAPH_LL_H
#define CDS_GRAPH_LL_H

#include<../CDS_LinkedList/CDS_LinkedList.h>
#include<../CDS_Array/CDS_DynamicArray.h>

//lil = (li)nked (l)ist
typedef struct stdGrapLL cdst_graph_lil;

struct stdGrapLL{

};

typedef struct stdGraphAdjan cdst_graph;

struct stdGraphAdjan{
    cdst_array* adjan_list;
};

void CDS_graph_lil_init();

void CDS_graph_lil_add();

void CDS_graph_lil_remove();

void CDS_graph_lil_bfs();
void CDS_graph_lil_dfs();

void CDS_graph_lil_destroy();

#endif // CDS_GRAPH_H
