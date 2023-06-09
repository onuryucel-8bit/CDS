#include "CDS_DoubleLinkedList.h"

//TODO test code
//TODO void CDS_Double_LinkedList_removeIndex(cdst_dou_lil_Data* list ,unsigned int index)

static cdst_dou_lil_Data* create_doubleNode(void* data,cdst_dou_lil_Data* next,cdst_dou_lil_Data* prev){

    cdst_dou_lil_Data* newNode = malloc(sizeof(cdst_dou_lil_Data));

    if(newNode == NULL)return 0;

    newNode->data = data;
    newNode->next = next;
    newNode->prev = prev;

    return newNode;
}

/**
*   init double linked list returns pointer to linked list
*/
cdst_dou_lil_List* CDS_Double_LinkedList_init(){

    cdst_dou_lil_List* newList = malloc(sizeof(cdst_dou_lil_List));

    if(newList == NULL)return 0;

    newList->head = NULL;

    return newList;
}

//----------------------------------------------------------------------------//

void CDS_Double_LinkedList_addLast(cdst_dou_lil_List* list,void* data){
    if(list == NULL)return;

    //example: list( .<--a<-->b-->. ) ADD(c);
    cdst_dou_lil_Data* newNode = create_doubleNode(data,NULL,NULL);//.<--c-->.

    //if list is empty
    if(list->head == NULL){
        list->head = newNode;//head = c
        return;
    }

    cdst_dou_lil_Data* current = list->head;//current = a

    while(current->next != NULL){
        current = current->next;
    }

    //current is b now
    current->next = newNode; //current(b)->next = c
    newNode->prev = current; //c->prev = current(b)
}

void CDS_Double_LinkedList_addFirst(cdst_dou_lil_List* list,void* data){

    if(list == NULL)return;

    cdst_dou_lil_Data* newNode = create_doubleNode(data,NULL,NULL);
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    //a<->b<->c ADD (x)         //head => a
    newNode->next = list->head; //x->a
    list->head->prev = newNode; //x<->a

    list->head = newNode; //head = x
}

void CDS_Double_LinkedList_addIndex(cdst_dou_lil_List* list,void* data,unsigned int index){

    //0   1   2
    //a<->b<->c index 1 , ADD(x)
    //a<->x<->b<->c final sitatuion

    if(list == NULL)return;

    unsigned int counter = 0;

    cdst_dou_lil_Data* current = list->head;
    while(counter < index && current != NULL){
        current = current->next;
        counter++;
    }

    //current node => b

    cdst_dou_lil_Data* newNode = create_doubleNode(data,NULL,NULL);//Create node x

    newNode->next = current;//x->next = b;
    newNode->prev = current->prev;//x->prev = a;

    current->prev = newNode;//b->prev = x;


}
//----------------------------------------------------------------------------//

void CDS_Double_LinkedList_removeLast(cdst_dou_lil_List* list){

   if(list == NULL)return;

   //example list: a<->b<->c<->d

   cdst_dou_lil_Data* current = list->head;//current = a
   while(current->next != NULL){
       current = current->next;
   }

   //current is now d
   cdst_dou_lil_Data* previousNode = current->prev;//prev = c

   previousNode->next = NULL; //c->next = NULL
   free(current);//free node d
}

void CDS_Double_LinkedList_removeFirst(cdst_dou_lil_List* list){

    if(list == NULL)return;

    //<--a<-->b-->

    cdst_dou_lil_Data* current = list->head;

    current->next->prev = NULL;//<--a-->b--> //b.prev = NULL

    list->head = current->next;//list->head = b;

    free(current);//free(node a);



}

void CDS_Double_LinkedList_removeIndex(cdst_dou_lil_Data* list ,unsigned int index){
}

//----------------------------------------------------------------------------//

void CDS_Double_LinkedList_destroy(cdst_dou_lil_List* list){

    // <--p a <-p-n-> b <-p-n-> c n-->

    cdst_dou_lil_Data* current = list->head;

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


