#ifndef CDS_QUEUE_H
#define CDS_QUEUE_H

#include"CDS_QueueLL.h"

//TODO add additional functions reverse,count...
//TODO void CDS_Queue_lil_compare()

cdst_queue_Holder* CDS_Queue_lil_init(enum cdsMemoryType type){
    cdst_queue_Holder* newQueue = malloc(sizeof(cdst_queue_Holder));

    if(!newQueue){
        return NULL;
    }

    newQueue->top = NULL;
    newQueue->type = type;

    return newQueue;
}

static cdst_queue_Data* queue_CreateNode(void* data){
    cdst_queue_Data* newNode = malloc(sizeof(cdst_queue_Data));

    if(!newNode){
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/**
*  adding element to end of linked list
*  head will be "top"
*/
void CDS_quel_add(cdst_queue_Holder* queue,void* data){

    //create newnode
    cdst_queue_Data* newNode = queue_CreateNode(data);

    //if queue is empty
    if(queue->top == NULL){
        queue->top = newNode;
        return;
    }

    //ENQUEUE(d);
    //a->b->c head of queue is a

    cdst_queue_Data* current = queue->top;

    while(current->next != NULL){
        current = current->next;
    }

    //a->b->c->d
    current->next = newNode;

}

void CDS_quel_remove(cdst_queue_Holder* queue){
    if(queue->top == NULL){
        return;
    }

    //a->b->c->d top of queue is a

    cdst_queue_Data* current = queue->top;//current = a;

    current = current->next;//current points out b now;

    free(queue->top);//free node a

    queue->top = current;//make the current top of queue

}

void CDS_Queue_lil_compare(){
}

/**
*  if queue empty return 1
*  else return 0
*/
int CDS_quel_isEmpty(cdst_queue_Holder* queue){

    if(queue->top == NULL)return 1;

    return 0;
}

/**
* returns first element of queue
*/
void* CDS_que_getFirst(cdst_queue_Holder* queue){
    return queue->top;
}

void CDS_Queue_lil_destroy(cdst_queue_Holder* queue){
    if (queue == NULL || queue->top == NULL) {
        return;
    }

    cdst_queue_Data* current = queue->top;
    cdst_queue_Data* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(queue);
}

#endif // CDS_QUEUE_H
