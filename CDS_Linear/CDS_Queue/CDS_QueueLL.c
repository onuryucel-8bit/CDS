#ifndef CDS_QUEUE_H
#define CDS_QUEUE_H

#include"CDS_QueueLL.h"

cdst_queue_Holder* CDS_Queue_LL_init(){
    cdst_queue_Holder* newQueue = malloc(sizeof(cdst_queue_Holder));

    if(!newQueue){
        return NULL;
    }

    newQueue->top = NULL;

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

void CDS_Queue_LL_enQueue(cdst_queue_Holder* queue,void* data){

    cdst_queue_Data* newNode = queue_CreateNode(data);

    if(queue->top == NULL){
        queue->top = newNode;
        return;
    }

    cdst_queue_Data* current = queue->top;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;

}

void CDS_Queue_LL_deQueue(cdst_queue_Holder* queue,void* data){
    if(queue->top == NULL){
        return;
    }

    cdst_queue_Data* current = queue->top;

    current = current->next;

    free(queue->top);

    queue->top = current;

}

void CDS_Queue_LL_destroy(cdst_queue_Holder* queue){

    cdst_queue_Data* current = queue->top;
    cdst_queue_Data* nextNode = current;

    while(current->next != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(queue);
    queue->top = NULL;
}

#endif // CDS_QUEUE_H
