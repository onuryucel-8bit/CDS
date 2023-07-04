#include "CDS_CircularLinkedList.h"

static cdst_circ_lil_Data* sta_circ_lil_createNode(void* data){

    cdst_circ_lil_Data* node = malloc(sizeof(cdst_circ_lil_Data));

    node->data = data;
    node->next = NULL;

    return node;
}

cdst_circ_lil_List* CDS_Circular_LinkedList_init(){

    cdst_circ_lil_List* list = malloc(sizeof(cdst_circ_lil_List));

    if(list == NULL)return;

    list->head = NULL;

    return list;
}

//------------ADD-----

void CDS_Circular_LinkedList_addLast(cdst_circ_lil_List* list,void* data){

    cdst_circ_lil_Data* newNode = sta_circ_lil_createNode(data);

    if(list == NULL)return;

    if(list->head == NULL){

        list->head = newNode;

        newNode->next = list->head;
    }

    cdst_circ_lil_Data* current = list->head;

    while(current->next == list->head){
        current = current->next;
    }

    current->next = newNode;
    newNode->next = list->head;

}

//------------REMOVE-----

void CDS_circular_linkedlist_removeLast(cdst_circ_lil_List* list){

    if(list == NULL)return;

    cdst_circ_lil_Data* current = list->head;

    if(current->next == list->head){

        free(list->head);

        return;
    }

    cdst_circ_lil_Data* pre = current;

    while(current->next != list->head){
        pre = current;
        current = current->next;
    }

    free(current);

    pre->next = list->head;


}
