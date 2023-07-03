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

void CDS_graph_lil_connectNodes(cdst_graph_lil* graph,int source,unsigned int n, ...){
    va_list args;
    va_start(args,n);
}

void CDS_graph_lil_addNode(cdst_graph_lil* graph,int data){

    //check for error
    if(graph == NULL)return;

    /*
    *   array
    *     0   -->list_0
    *     1   -->list_1
    *     .
    *     .
    *
    */
    //if array empty
    if(graph->adjan_list->arrayHead == NULL){

        //create array
        graph->adjan_list = CDS_dynamicArray_init(5);

        //add data
        //CDS_dynamicArray_addLast(graph->adjan_list,data);

        return;
    }

    if(CDS_graph_lil_find_in_array(graph,data))return;

    //CDS_dynamicArray_addLast(graph->adjan_list,data);

}

int CDS_graph_lil_find_in_array(cdst_graph_lil* graph,int data){

    if(graph == NULL)return 0;

    //unsigned int ARRAY_SIZE = graph->adjan_list->index;


    return 0;
}

void CDS_graph_lil_destroy(cdst_graph_lil* graph){

    //destroy list
    for(int i = 0; i < graph->adjan_list->capacity; i++){
        //CDS_LinkedList_destroy(graph->adjan_list->arrayHead[i]); ???
    }

    //destroy array
    CDS_dynamicArray_destroy(graph->adjan_list);
    //destroy graph
    free(graph);
}
