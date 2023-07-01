#include "CDS_LinkedList.h"

//cdst c data structure type

///initiliaze the list struct
cdst_linkedList_List* CDS_LinkedList_init() {

    //memory allocetion for list
    cdst_linkedList_List* list = malloc(sizeof(cdst_linkedList_List));

    //eger bellekten yer alinamadiysa
    if (!list) {
        return NULL;
    }

    //listeyi bos olarak dondur
    list->head = NULL;
    return list;
}

///create node
static cdst_linkedList_Data* createNode(void* data){

    //memory allocation for node
    cdst_linkedList_Data* newNode = malloc(sizeof(cdst_linkedList_Data));

    //error check
    if(!newNode){
       // perror("Failed to create newNode in CDS_LinkedList");
        return NULL;
    }

    //put the data inside of node
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


//-----------------------------------------------------------//
//-----------------------------ADD---------------------------//
//-----------------------------------------------------------//

/**
*   adds element to head of list
*
*/
void CDS_LinkedList_addFirst(cdst_linkedList_List* list,void* data){

    //if list empty make the element list of head
    if(list->head == NULL){
        list->head = createNode(data);
        return;
    }

    //create Nodes
    cdst_linkedList_Data* newNode = createNode(data);

    //connect new node to list head
    newNode->next = list->head;

    //make list head newNode
    list->head = newNode;

}

/**
*   adds element to end of list
*/
void CDS_LinkedList_addLast(cdst_linkedList_List* list,void* data){

    //if list empty
    if(list->head == NULL){
        list->head = createNode(data);
        return;
    }

    //travelsing linked list
    cdst_linkedList_Data* current = list->head;
    while(current->next != NULL){
        current = current->next;
    }

    //add element end of list
    current->next = createNode(data);
}


//-----------------------------------------------------------//
//---------------------------REMOVE--------------------------//
//-----------------------------------------------------------//

/**
*   remove first element from list
*/
void CDS_LinkedList_removeFirst(cdst_linkedList_List* list){

    //check first element
    if(list->head == NULL){

        //if head has next element
        if(list->head->next != NULL){
            cdst_linkedList_Data* current = list->head->next;

            //free list head
            free(list->head);

            //make the next node head of list
            list->head = current;

            return;
        }

        free(list->head);
        list->head = NULL;

        return;
    }
}

/**
*   remove last element from list
*/
void CDS_LinkedList_removeLast(cdst_linkedList_List* list){

    //is list null
    if(list == NULL || list->head == NULL)return;

    cdst_linkedList_Data* current = list->head;
    cdst_linkedList_Data* previous = NULL;

    if (current->next == NULL) {
        // Only one element in the list
        list->head = NULL;
        free(current);
        return;
    }

    //go end of list
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }

    //c = previous d = current
    //A->B->C->D
    previous->next = NULL;//c->next = null
    free(current);//free d


}

void CDS_LinkedList_removeIndex(cdst_linkedList_List* list,unsigned int index){

    unsigned int counter = 0;

    //is list null
    if(list == NULL || list->head == NULL)return;

    cdst_linkedList_Data* current = list->head;
    cdst_linkedList_Data* previous = NULL;

    if (current->next == NULL && index == 0) {
        list->head = NULL;
        free(current);
        return;
    }


    while(current->next != NULL && counter != index){

        previous = current;
        current = current->next;
        counter++;
    }

    if(counter != index)return;

    //c = previous d = current
    //A->B->C->D
    previous->next = NULL;//c->next = null
    free(current);//free d

}


//-----------------------------------------------------------//
//---------------------------UTILS---------------------------//
//-----------------------------------------------------------//

///Checks if lisf of head empty
int CDS_LinkedList_isEmpty(cdst_linkedList_List* list){
    if(list->head == NULL){
        return 1;
    }

    return 0;
}

static void sta_linkedList_reverseTheList(cdst_linkedList_Data* current,cdst_linkedList_List* list){

    //move to next node
    if(current->next->next != NULL){
        sta_linkedList_reverseTheList(current->next,list);

    //if node is end of list
    }
    if(current->next->next == NULL){

        current->next->next = current;
        list->head = current->next;

        return;
    }

    current->next->next = current;
    //current->next = NULL;

}

void CDS_LinkedList_reverseRec(cdst_linkedList_List* list){
    if(list->head->next == NULL){
        return;
    }

    sta_linkedList_reverseTheList(list->head,list);


}

void CDS_LinkedList_reverse(cdst_linkedList_List* list){

    if(list == NULL || list->head == NULL){
        return;
    }

    cdst_linkedList_Data* current  = list->head;
    cdst_linkedList_Data* previous = NULL;
    cdst_linkedList_Data* tempNode = NULL;

    while(current->next != NULL){

        tempNode = current->next;

        current->next = previous;

        previous = current;
        current = tempNode;

    }

    current->next = previous;

    list->head = current;

}


int CDS_LinkedList_SearchElement(cdst_linkedList_List* list,void* data,int (*compare)(void* data, void* nodeData)){

    cdst_linkedList_Data* current = list->head;

    while(current != NULL){
        if(compare(data,current->data) == 1){
            return 1;
        }
        current = current->next;
    }

    return 0;
}

/**
*  if list or list head is equal to null then return NULL
*  returns pointer of data
*  if data doesnt found return NULL
*
*  compare MUST
*  data == node->data return 1
*/
void* CDS_LinkedList_FindElement(cdst_linkedList_List* list,void* data,int (*compare)(void* data,void* nodeData) ){

    //is list empty
    if(list == NULL || list->head == NULL) return NULL;

    cdst_linkedList_Data* current = list->head;
    //traveling linked list
    while(current != NULL){
        //found the data
        if(compare(data,current->data)){
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

/**
*  it will return total number of nodes
*/
unsigned int CDS_LinkedList_countList(cdst_linkedList_List* list){
    cdst_linkedList_Data* current = list->head;
    unsigned int i = 0;
    while(current != NULL){
        i++;
        current = current->next;
    }
    return i;
}

/**
*   bubble sort
*
*   DEFINE Compare func(a,b)
*   if (a > b) return 1 OR if (a >= b) return 1
*   else return 0
*/
void CDS_linkedlist_sort(cdst_linkedList_List* list,int (*compare)(void* data,void* cmp_data) ){

    if(list == NULL || list->head == NULL || list->head->next == NULL)return;

    cdst_linkedList_Data* current = list->head;
    cdst_linkedList_Data* nextNode = NULL;
    void* tempData = NULL;

    unsigned int size = CDS_LinkedList_countList(list);

    for(int i = 0;i < size - 1; i++){

        for(int j = 0; j < size - i - 1; j++){

            current = list->head;
            nextNode = current->next;

            if(compare(current->data,nextNode->data)){
                tempData = current->data;
                current->data = nextNode->data;
                nextNode->data = tempData;
            }

        }//for j end

    }//for i end

}


///it frees linked list
void CDS_LinkedList_destroy(cdst_linkedList_List* list){

    if(list == NULL){
        return;
    }

    cdst_linkedList_Data* current = list->head;

    cdst_linkedList_Data* nextNode = current;

    //free nodes
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    //free list
    free(list);


}
