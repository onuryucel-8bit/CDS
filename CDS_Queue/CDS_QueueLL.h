#ifndef CDS_OUEUE_LL_H
#define CDS_OUEUE_LL_H

#include<stdlib.h>

#include "../CDS_generalData/allocationEnumData.h"

///TODO compare();

typedef struct stdQueueNode cdst_queue_Data;

struct stdQueueNode{
    void* data;
    cdst_queue_Data* next;
};

typedef struct stdQueue cdst_queue_Holder;

struct stdQueue{
    cdst_queue_Data* top;
    char type;
};

cdst_queue_Holder* CDS_Queue_lil_init(enum cdsMemoryType type);
void CDS_quel_add(cdst_queue_Holder* queue,void* data);
void CDS_quel_remove(cdst_queue_Holder* queue);

void CDS_Queue_lil_compare();

void* CDS_que_getFirst(cdst_queue_Holder* queue);

int CDS_quel_isEmpty(cdst_queue_Holder* queue);

void CDS_Queue_lil_destroy(cdst_queue_Holder* queue);


#endif // CDS_OUEUE_LL_H
