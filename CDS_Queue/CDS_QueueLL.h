#ifndef CDS_OUEUE_LL_H
#define CDS_OUEUE_LL_H

#include<stdlib.h>

///TODO compare();

typedef struct stdQueueNode cdst_queue_Data;

struct stdQueueNode{
    void* data;
    cdst_queue_Data* next;
};

typedef struct stdQueue cdst_queue_Holder;

struct stdQueue{
    cdst_queue_Data* top;
};

cdst_queue_Holder* CDS_Queue_LL_init();
void CDS_Queue_LL_enQueue(cdst_queue_Holder* queue,void* data);
void CDS_Queue_LL_deQueue(cdst_queue_Holder* queue,void* data);

void CDS_Queue_LL_compare();

void CDS_Queue_LL_destroy(cdst_queue_Holder* queue);


#endif // CDS_OUEUE_LL_H
