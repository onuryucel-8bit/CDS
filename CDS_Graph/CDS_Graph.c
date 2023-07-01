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

    /*
    *   array
    *     0   -->list_0
    *     1   -->list_1
    *     .
    *     .
    *
    */
    if(graph->adjan_list->arrayHead == NULL){

        graph->adjan_list = CDS_dynamicArray_init(5);

        //CDS_dynamicArray_addLast(graph->adjan_list,data);

        return;
    }

    if(CDS_graph_lil_find_in_array(graph,data))return;

    //CDS_dynamicArray_addLast(graph->adjan_list,data);

}

int CDS_graph_lil_find_in_array(cdst_graph_lil* graph,int data){

    if(graph == NULL)return 0;

    unsigned int ARRAY_SIZE = graph->adjan_list->index;

    for(int i = 0; i <ARRAY_SIZE;i++){
            //if(data == *(int*)(graph->adjan_list->arrayHead[i])) {
            //return 1;
        //}
    }

    return 0;
}



void CDS_graph_lil_destroy(cdst_graph_lil* graph){
    free(graph);
}



