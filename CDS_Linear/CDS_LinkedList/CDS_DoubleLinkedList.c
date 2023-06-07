#include "CDS_DoubleLinkedList.h"


static cdst_douLL_Data* create_doubleNode(void* data,cdst_douLL_Data* next,cdst_douLL_Data* prev){

    cdst_douLL_Data* newNode = malloc(sizeof(cdst_douLL_Data));

    if(newNode == NULL)return 0;

    newNode->data = data;
    newNode->next = next;
    newNode->prev = prev;

    return newNode;
}

///init double linked list returns pointer to linked list
cdst_douLL_List* CDS_Double_LinkedList_init(){

    cdst_douLL_List* newList = malloc(sizeof(cdst_douLL_List));

    if(newList == NULL)return 0;

    newList->head = NULL;

    return newList;
}


//----------------------------------------------------------------------------//

void CDS_Double_LinkedList_addLast(cdst_douLL_List* list,void* data){
    if(list == NULL)return;

    cdst_douLL_Data* newNode = create_doubleNode(data,NULL,NULL);
    if(list->head == NULL){
        list->head = newNode;
        return;
    }

    cdst_douLL_Data* current = list->head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}



//----------------------------------------------------------------------------//

void CDS_Double_LinkedList_removeLast(cdst_douLL_List* list){

   if(list == NULL)return;

   cdst_douLL_Data* current = list->head;
   while(current->next != NULL){
       current = current->next;
   }

   cdst_douLL_Data* prev = current->prev;

   free(current->prev);
   free(current->next);
   free(current);

   prev->next = NULL;

}



//----------------------------------------------------------------------------//

void CDS_Double_LinkedList_destroy(cdst_douLL_List* list){

    // <--p a <-p-n-> b <-p-n-> c n-->

    cdst_douLL_Data* current = list->head;

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


