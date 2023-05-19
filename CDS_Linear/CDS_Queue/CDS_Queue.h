#ifndef CDS_OUEUE_LL_H
#define CDS_OUEUE_LL_H

#include<stdlib.h>

typedef struct stdQueueNode queueNode;

struct stdQueueNode{
    void* data;
    queueNode* next;
};

typedef struct stdQueue queueLL;

struct stdQueue{
     queueNode* top;
};

queueLL* CDS_Queue_LL_init();
void CDS_Queue_LL_enQueue(queueLL* queue,void* data);
void CDS_Queue_LL_deQueue(queueLL* queue,void* data);
void CDS_Queue_LL_destroy(queueLL* queue);

#endif // CDS_OUEUE_LL_H
