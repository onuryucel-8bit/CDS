#include "CDS_StackLL.h"


static cdst_stack_Data* CDS_Stack_createNode(void* data){

    cdst_stack_Data* newNode = (cdst_stack_Data*)malloc(sizeof(cdst_stack_Data));

    assert(newNode != NULL);
    if(newNode == NULL){
        printf("NEW node NULL\n");
        return NULL;
    }

    newNode->data = data;

    newNode->next = NULL;

    return newNode;
}

cdst_stack_Holder* CDS_StackLL_init(){

     cdst_stack_Holder* stack = (cdst_stack_Holder*)malloc(sizeof(cdst_stack_Holder));

     assert(stack != NULL);
     if(stack == NULL){
        printf("NULLL");
        return NULL;
     }

     stack->top = NULL;

     return stack;

}

void CDS_StackLL_push(cdst_stack_Holder* stack,void* data){

    cdst_stack_Data* newNode = CDS_Stack_createNode(data);


    assert(stack != NULL);
/*
    printf("stack->top %p\n",stack->top);
    printf("newNode->next %p\n",newNode->next);
    printf("newNode->data %p\n",newNode->data);
    printf("----------\n");
*/
    if(stack->top == NULL){

        stack->top = newNode;
     /*   printf("newNode  %p\n",newNode);
        printf("FIRST stack->top !! %p\n",stack->top);
        printf("-----DONE-----\n");*/
        return;
    }


    //printf("newNode  %p\n",newNode);
    newNode->next = stack->top;
    //printf("newNode->next !! %p\n",newNode->next);
    stack->top = newNode;
    //printf("stack->top !! %p\n",stack->top);
    //printf("----DONE-----\n");

}

void CDS_StackLL_pop(cdst_stack_Holder* stack){
    if(stack->top == NULL){
        return;
    }

    cdst_stack_Data* oldTop = stack->top;
    stack->top = oldTop->next;

    free(oldTop);
}

cdst_stack_Data* CDS_StackLL_top(cdst_stack_Holder* stack){
    return stack->top;
}

int CDS_StackLL_isEmpty(cdst_stack_Holder* stack){
    if(stack->top == NULL){
        return 1;
    }

    return 0;
}

void CDS_StackLL_destroy(cdst_stack_Holder* stack){

    cdst_stack_Data* current = stack->top;

    cdst_stack_Data* nextNode = current;

    while(current != NULL){
        nextNode = current->next;
        free(current->data);
        free(current);
        current = nextNode;
    }

    free(stack);
}
