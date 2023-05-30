#include "CDS_DoubleLinkedList.h"


static cds_douLL_Data* create_doubleNode(void* data,cds_douLL_Data* next,cds_douLL_Data* prev){

    cds_douLL_Data* newNode = malloc(sizeof(cds_douLL_Data));

    if(newNode == NULL)return 0;

    newNode->data = data;
    newNode->next = next;
    newNode->prev = prev;

    return newNode;
}

cds_douLL_List* CDS_Double_LinkedList_init(){

    cds_douLL_List* newList = malloc(sizeof(cds_douLL_List));

    if(newList == NULL)return 0;

    newList->head = NULL;

    return newList;
}

void CDS_Double_LinkedList_addLast(cds_douLL_List* list,void* data){
    if(list == NULL)return;

    cds_douLL_Data* newNode = create_doubleNode(data,NULL,NULL);
    if(list->head == NULL){
        list->head = newNode;
        return;
    }

    cds_douLL_Data* current = list->head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void CDS_Double_LinkedList_destroy(cds_douLL_List* list){

    // <--p a <-p-n-> b <-p-n-> c n-->

    cds_douLL_Data* current = list->head;

    while(current->next != NULL){
        free(current->prev);
        current->prev = NULL;

        current = current->next;
    }

    current = list->head;
    while(current->next != NULL){

    }

    free(list->head);
    free(list);

    list = NULL;
}


