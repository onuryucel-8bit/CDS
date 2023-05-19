#include "CDS_StackLL.h"


static stackNode* CDS_Stack_createNode(int data){

    stackNode* newNode = malloc(sizeof(stackNode));

    if(!newNode){
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

cstack* CDS_StackLL_init(){

     cstack* stack = malloc(sizeof(cstack));

     if(!stack){
        return NULL;
     }

     stack->top = NULL;

     return stack;

}

void CDS_StackLL_push(cstack* stack,int data){

    stackNode* newNode = CDS_Stack_createNode(data);

    newNode->next = stack->top;
    stack->top = newNode;

}

void CDS_StackLL_pop(cstack* stack){
    if(stack->top == NULL){
        return;
    }

    stackNode* newTop = stack->top->next;

    free(stack->top);

    stack->top = newTop;

}

stackNode* CDS_StackLL_top(cstack* stack){
    return stack->top;
}

int CDS_StackLL_isEmpty(cstack* stack){
    if(stack->top == NULL){
        return 1;
    }

    return 0;
}

void CDS_StackLL_destroy(cstack* stack){

    stackNode* current = stack->top;

    stackNode* nextNode = current;

    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(stack);
}
