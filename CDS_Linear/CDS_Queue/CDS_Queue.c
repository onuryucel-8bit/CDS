#ifndef CDS_QUEUE_H
#define CDS_QUEUE_H

#include"CDS_Queue.h"

queueLL* CDS_Queue_LL_init(){
    queueLL* newQueue = malloc(sizeof(queueLL));

    if(!newQueue){
        return NULL;
    }

    newQueue->top = NULL;

    return newQueue;
}

static queueNode* queue_CreateNode(void* data){
    queueNode* newNode = malloc(sizeof(queueNode));

    if(!newNode){
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void CDS_Queue_LL_enQueue(queueLL* queue,void* data){

    queueNode* newNode = queue_CreateNode(data);

    if(queue->top == NULL){
        queue->top = newNode;
        return;
    }

    queueNode* current = queue->top;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;

}

void CDS_Queue_LL_deQueue(queueLL* queue,void* data){
    if(queue->top == NULL){
        return;
    }
}
void CDS_Queue_LL_destroy(queueLL* queue){}

#endif // CDS_QUEUE_H
