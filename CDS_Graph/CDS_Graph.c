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

static cdst_graph_interface_node* to_graph_interfaceNode(void* data){
    return (cdst_graph_interface_node*)(data);
}

int compare_std_func(void* data_1,void* data_2){
    int a = to_graph_interfaceNode(data_1)->node_name; //interface node name
    int b = (int*)data_2; //int


    if(a == b)return 1;
    return 0;
}

/**
* n amount of nodes
* ... connection nodes
*/
void CDS_graph_lil_connectNodes(cdst_graph_lil* graph,int source,unsigned int n, ...){

    va_list args;
    va_start(args,n);

    //is source node valid
    if(!CDS_dynamicArray_searchElement(graph->adjan_list,(void*)source,compare_std_func))return;


    //check for connection errors !!
        //code here

    //change with dynamic array
    void* node[5]; int index = 0;

    //connect nodes to the source node
    for(int i = 0; i < n; i++){

        //find the source node
        cdst_graph_interface_node* interface_node = (cdst_graph_interface_node*)CDS_dynamicArray_findElement(graph->adjan_list,(void*)source,compare_std_func);

        //check error
        if(interface_node == NULL) return;

        //take node name
        void* connect_node = (void*)va_arg(args,int);
        node[index] = connect_node;
        index++;

        //connect the source to node_t
        CDS_LinkedList_addLast(interface_node->linked_list_connection,connect_node);
    }


    //make connection node_t to the source node
    for(int i = 0; i < n; i++){

        //if they dont exist in array, create and put inside the array
        if(!CDS_dynamicArray_searchElement(graph->adjan_list,node[i],compare_std_func)){
            CDS_graph_lil_addNode(graph,(int*)node[i]);
        }
    }
    va_end(args);
}

//16.07.23 checked
/**
*  adding node to graph
*/
void CDS_graph_lil_addNode(cdst_graph_lil* graph,int nodeName){

    //check for error
    if(graph == NULL)return;

    //create new interface node
    cdst_graph_interface_node* newNode = sta_create_graph_node_interface(nodeName);

    //create linked list
    cdst_linkedList_List* linkedList = CDS_LinkedList_init();

    //check error
    //if newnode == null or linkedlist == null return;

    //connect linked list to interface node
    newNode->linked_list_connection = linkedList;

    //add list to adjan array
    CDS_dynamicArray_addLast(graph->adjan_list,newNode);

}

void CDS_graph_test_print(cdst_graph_lil* graph){

    /*for(int i = 0; i < graph->adjan_list->index; i++){
        cdst_graph_interface_node* node = (cdst_graph_interface_node*)(graph->adjan_list->arrayHead[i].data );
        printf("array: NODE NAME %i \n",  node->node_name );

        cdst_linkedList_Data* current = node->linked_list_connection->head;
        while(current != NULL){
            printf("  list_data:%i", (int*)(current->data));
            current = current->next;
        }
        printf("\n");
    }*/
}

void CDS_graph_lil_destroy(cdst_graph_lil* graph){

    //destroy list
    //(int i = 0; i < graph->adjan_list->capacity; i++){
        //CDS_LinkedList_destroy(graph->adjan_list->arrayHead[i]); ???
    //

    //destroy array
    //CDS_dynamicArray_destroy(graph->adjan_list);
    //destroy graph
    free(graph);
}
