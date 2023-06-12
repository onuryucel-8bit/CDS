#ifndef CDS_QUEUE_ARRAY_H
#define CDS_QUEUE_ARRAY_H

#include<stdlib.h>


typedef struct stdQueueArrData cdst_queueArray_Data;

struct stdQueueArrData{
    void* data;
};

typedef struct stdQueueArr queueArr;

struct stdQueueArr{
     cdst_queueArray_Data* top;
     unsigned int size;
};

queueArr* CDS_Queue_arr_init();
void CDS_Queue_arr_enQueue(queueArr* queue,void* data);
void CDS_Queue_arr_deQueue(queueArr* queue,void* data);
void CDS_Queue_arr_destroy(queueArr* queue);

#endif
