#include "CDS_StackLL.h"

#include <stdio.h>

void testStackVersion(){
    printf("VERSION:STACK_ALLOC : CDS_stack_lil TEST STARTED\n");

    cdst_stack_Holder* stack = CDS_stack_lil_init(CDS_STACK_ALLOCATE);

    if(stack == NULL){
        printf("ERROR : File %s CDS_stack_lil_init line %d",__FILE__,__LINE__);
        return;
    }

    printf("VERSION:STACK_ALLOC : stack init done \n");
    //PUSH 50
    int data = 50;

    CDS_stack_lil_push(stack,&data);

    void* top = CDS_stack_lil_top(stack);

    if(top == &data &&  (*(int*)top) == data){
        printf("TRUE : top == &data && (*(int*)top) == data\n");
    }

    //POP
    CDS_stack_lil_pop(stack);

    if(CDS_stack_lil_isEmpty(stack)){
        printf("Stack is empty \n");
    }

    CDS_stack_lil_destroy(stack);
    printf("VERSION:STACK_ALLOC : CDS_stack_lil TEST FINISHED...\n");
}

void testHeapVersion(){

}

int main(){

    testStackVersion();

    testHeapVersion();
}

