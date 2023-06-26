#include"CDS_Graph.h"

void CDS_graph_lil_init(){

    int size = 5;
    cdst_array* new_adjaceny_array = CDS_dynamicArray_init(size);

    for(int i = 0; i < size; i++){

        cdst_linkedList_List* linked_list = CDS_LinkedList_init();

        CDS_dynamicArray_addLast(new_adjaceny_array,linked_list);

    }

    cdst_graph_lil* graph = (cdst_graph_lil*)malloc(sizeof(cdst_graph_lil));

    graph->adjan_list = new_adjaceny_array;

    //return graph;
}

void CDS_graph_lil_add(cdst_graph_lil* graph,int data){

    if(graph == NULL)return;

    //cdst_array* array = graph->adjan_list;

    //array[i]

    //CDS_LinkedList_addLast(array_cell,(void*)data);

    //CDS_LinkedList_addLast(graph.array,int data);
}
