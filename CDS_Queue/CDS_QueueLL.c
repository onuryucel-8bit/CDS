#include"CDS_QueueLL.h"

//core functions finished except compare 26.06.23

//TODO add additional functions reverse,count...
//TODO void CDS_Queue_lil_compare()

cdst_queue_Holder* CDS_Queue_lil_init(){
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

/**
*  adding element to end of linked list
*  head will be "top"
*/
void CDS_Queue_lil_enQueue(cdst_queue_Holder* queue,void* data){

    cdst_queue_Data* newNode = queue_CreateNode(data);

    if(queue->top == NULL){
        queue->top = newNode;
        return;
    }

    //a->b->c head queue is a
    cdst_queue_Data* current = queue->top;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;

}

void CDS_Queue_lil_deQueue(cdst_queue_Holder* queue,void* data){
    if(queue->top == NULL){
        return;
    }

    //a->b->c->d top of queue is a

    cdst_queue_Data* current = queue->top;//current = a;

    current = current->next;//current points out b now;

    free(queue->top);//free node a

    queue->top = current;//make the current top of queue

}

void CDS_Queue_lil_compare(cdst_q){
}

/**
*  if queue empty return 1
*  else return 0
*/
int CDS_Queue_lil_isEmpty(cdst_queue_Holder* queue){

    if(queue->top == NULL)return 1;

    return 0;
}

void CDS_Queue_lil_destroy(cdst_queue_Holder* queue){

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
