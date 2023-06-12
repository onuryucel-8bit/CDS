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

/**
    initiliaze stack
*/
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

///----------------------ADD----------------------------//

/**

*/
void CDS_StackLL_push(cdst_stack_Holder* stack,void* data){

///----------------------REMOVE----------------------------//


    cdst_stack_Data* newNode = CDS_Stack_createNode(data);


    assert(stack != NULL);

    if(stack->top == NULL){

        stack->top = newNode;

        return;
    }

    newNode->next = stack->top;

    stack->top = newNode;


}
/**
*
*  pops the top of the stack
*/
void CDS_StackLL_pop(cdst_stack_Holder* stack){
    if(stack->top == NULL){
        return;
    }

    cdst_stack_Data* oldTop = stack->top;
    stack->top = oldTop->next;

    free(oldTop);

}

///----------------------UTILS----------------------------//

/**
*  Compare of contents of stacks
*  if stacks equal content return 1
*  else return 0
*  for error -1
*/
void CDS_StackLL_compare(cdst_stack_Holder* stack,cdst_stack_Holder* cmpStack,int compare(void* data1,void* data2)){

    if(stack == NULL || stack->top == NULL || cmpStack == NULL || cmpStack->top == NULL){
        return -1;
    }

    cdst_stack_Data* current = stack->top;
    cdst_stack_Data* cmpCurrent = cmpStack->top;

    while(current != NULL && cmpCurrent != NULL){

        current = current->next;
        cmpCurrent = cmpCurrent->next;

        if(current == NULL || cmpCurrent == NULL){
            return 0;
        }
    }
}

/**
*  returns top of stack
*/
void* CDS_StackLL_top(cdst_stack_Holder* stack){
    return stack->top->data;
}

/**
* if stack is null return 1
* else 0
*/
int CDS_StackLL_isEmpty(cdst_stack_Holder* stack){
    if(stack->top == NULL){
        return 1;
    }
    return 0;
}

/**
*  returns top of stack in char format
*/
char CDS_StackLL_getType_char_Top(cdst_stack_Holder* stack){
    return *(char*)(stack->top->data);
}

/**
*  returns top of stack in int format
*/
int CDS_StackLL_getType_int_Top(cdst_stack_Holder* stack){
    return *(int*)(stack->top->data);
}

/**
*  frees stack and data
*/
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
