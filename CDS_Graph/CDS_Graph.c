#include"CDS_Graph.h"

cdst_graph_lil* CDS_graph_lil_init(){

    int size = 5;
    cdst_array* new_adjaceny_array = CDS_dynamicArray_init(size);

    for(int i = 0; i < size; i++){

        cdst_linkedList_List* linked_list = CDS_LinkedList_init();

        CDS_dynamicArray_addLast(new_adjaceny_array,linked_list);

    }

    cdst_graph_lil* graph = (cdst_graph_lil*)malloc(sizeof(cdst_graph_lil));

    graph->adjan_list = new_adjaceny_array;

    return graph;
}

int compare_std_func(void* data_1,void* data_2){
    int a = *(int*)data_1;
    int b = *(int*)data_2;

    if(a == b)return 1;
    return 0;
}

void CDS_graph_lil_connectNodes(cdst_graph_lil* graph,int source,unsigned int n, ...){

    va_list args;
    va_start(args,n);

    //check nodes if there inside the adjan list
    for(int i = 0; i < n; i++){
        void* node =(void*)(va_arg(args,int));

        //if they not put inside adjan list
        if(CDS_dynamicArray_searchElement(graph->adjan_list,node,compare_std_func) == 0 ){
            CDS_dynamicArray_addLast(graph->adjan_list,node);

            //connect with source node
            /*
            *  let SOURCE NODE : c
            *  a->c
            *  b->c
            *  c->
            */
        }
    }


    //find the source node index in adjan list
    /*
    *  let SOURCE NODE : c
    *  a->c
    *  b->c
    *  c->a->b
    */
    //connect with others


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

    //CDS_dynamicArray_addLast(graph->adjan_list,data);

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
