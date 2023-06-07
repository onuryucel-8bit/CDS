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

///adds Element to head of list
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

///adds element to end of list
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

void CDS_LinkedList_addAfterIndex(cdst_linkedList_List* list,void* data,unsigned int index){}
void CDS_LinkedList_addAfterData(cdst_linkedList_List* list,void* data,void* indexData){}

//-----------------------------------------------------------//
//---------------------------REMOVE--------------------------//
//-----------------------------------------------------------//

///remove first element from list
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

///remove last element from list
void CDS_LinkedList_removeLast(cdst_linkedList_List* list){

    //check list is null
    if(list->head == NULL){
        return;
    }

    cdst_linkedList_Data* current = list->head;
    cdst_linkedList_Data* previous = NULL;

    if (current->next == NULL) {
        // Only one element in the list
        list->head = NULL;
        free(current);
        return;
    }

    //!!! HATA VAR !!!!//
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);


}

void CDS_LinkedList_removeAfterIndex(cdst_linkedList_List* list,unsigned int index){}
void CDS_LinkedList_removeAfterData(cdst_linkedList_List* list,void* data);

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

void CDS_LinkedList_reverse(cdst_linkedList_List* list){}
void CDS_LinkedList_Compare(cdst_linkedList_List* firstList, cdst_linkedList_List* secondList){}
void* CDS_LinkedList_SearchElement(cdst_linkedList_List* list){return 0;}
int  CDS_LinkedList_FindElement(cdst_linkedList_List* list){return 0;}

///yaklasik olarak [i] islemini yapar
void* CDS_LinkedList_GetData(cdst_linkedList_List* list,unsigned int index){return 0;}

///it frees linked list
void CDS_LinkedList_destroy(cdst_linkedList_List* list){

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
    list->head = NULL;
}

