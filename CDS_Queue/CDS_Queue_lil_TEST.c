#include <stdio.h>
#include <stdlib.h>

#include "CDS_QueueLL.h"

void queueHeapTest(){

}

void printQue_INT(cdst_queue_Data* first){
    cdst_queue_Data* current = first;

    while(current != NULL){
        printf("data = %i \n", *(int*)(current->data));
        current = current->next;
    }
}

void queueStackTest(){
    printf("Version:STACK_ALLOC : CDS_Queue_lil TEST STARTED\n");
    cdst_queue_Holder* queue = CDS_Queue_lil_init(CDS_STACK_ALLOCATE);

    if(queue == NULL){
        printf("ERROR: null queue \n");
        return;
    }

    int testINT = 10;
    int testINT_2 = 68;
    int testINT_3 = 268;

    CDS_quel_add(queue,&testINT);

    CDS_quel_add(queue,&testINT_2);
    CDS_quel_add(queue,&testINT_3);

    printf("=========\n");
    cdst_queue_Data* top = CDS_que_getFirst(queue);
    printQue_INT(top);

    CDS_quel_remove(queue);

    printf("=========\n");
    top = CDS_que_getFirst(queue);
    printQue_INT(top);


    if(CDS_quel_isEmpty(queue)){
        printf("Queue is empty\n");
    }else{
        printf("Queue is not empty\n");
    }

    CDS_Queue_lil_destroy(queue);
    printf("Version:STACK_ALLOC : CDS_Queue_lil TEST END\n");
}

int main(){
   queueHeapTest();
   queueStackTest();
}
