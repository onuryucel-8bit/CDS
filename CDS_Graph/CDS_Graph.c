#include"CDS_Graph.h"

static cdst_graph_interface_node* sta_create_graph_node_interface(int nodeName){

    cdst_graph_interface_node* newNode = malloc(sizeof(cdst_graph_interface_node));

    if(newNode == NULL)return NULL;

    newNode->node_name = nodeName;
    newNode->linked_list_connection = NULL;

    return newNode;
}


/**
*  it will return graph with ALL(adjanceny_array.data = NULL)
*/
cdst_graph_lil* CDS_graph_lil_init(){

    //create array with size of 5
    int size = 5;
    cdst_array* new_adjaceny_array = CDS_dynamicArray_init(size);

    cdst_graph_lil* graph = (cdst_graph_lil*)malloc(sizeof(cdst_graph_lil));

    if(graph == NULL || new_adjaceny_array == NULL ){
        return NULL;
    }

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

        void* node = malloc(sizeof(int));

        if(node == NULL)return;

        node = (void*)(va_arg(args,int));

        //if they not put inside adjan list
        if(CDS_dynamicArray_searchElement(graph->adjan_list,node,compare_std_func) == 0 ){

            CDS_dynamicArray_addLast(graph->adjan_list,node);

            //connect with source node
            /*
            *  let SOURCE NODE == c
            *  a->c
            *  b->c
            *  c->
            */

            cdst_array_Data* array = CDS_dynamicArray_getLastElement(graph->adjan_list);

            //create linked list
            cdst_linkedList_List* list = CDS_LinkedList_init();
            //connect with source node
            CDS_LinkedList_addLast(list,node);

            //add list to adjan array list
            array->data = list;
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


void CDS_graph_lil_addNode(cdst_graph_lil* graph,int nodeName){

    //check for error
    if(graph == NULL)return;

    cdst_graph_interface_node* newNode = sta_create_graph_node_interface(nodeName);

    cdst_linkedList_List* linkedList = CDS_LinkedList_init();

    //if newnode == null or linkedlist == null return;

    newNode->linked_list_connection = linkedList;

    CDS_dynamicArray_addLast(graph->adjan_list,newNode);

}

void CDS_graph_test_print(cdst_graph_lil* graph){

    for(int i = 0; i < graph->adjan_list->index; i++){
        cdst_graph_interface_node* node = (cdst_graph_interface_node*)(graph->adjan_list->arrayHead[i].data );
        printf("%i \n",  node->node_name );
    }
}

void CDS_graph_lil_destroy(cdst_graph_lil* graph){

    //destroy list
    //(int i = 0; i < graph->adjan_list->capacity; i++){
        //CDS_LinkedList_destroy(graph->adjan_list->arrayHead[i]); ???
    //}

    //destroy array
    //CDS_dynamicArray_destroy(graph->adjan_list);
    //destroy graph
    free(graph);
}
