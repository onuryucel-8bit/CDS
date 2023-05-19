#ifndef CDS_OUEUE_LL_H
#define CDS_OUEUE_LL_H

void CDS_Queue_LL_init();
void CDS_Queue_LL_enQueue(QueueLL* queue,void* data);
void CDS_Queue_LL_deQueue(QueueLL* queue,void* data);
void CDS_Queue_LL_destroy(QueueLL* queue);

#endif // CDS_OUEUE_LL_H
