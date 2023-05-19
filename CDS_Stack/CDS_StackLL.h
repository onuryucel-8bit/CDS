#ifndef CDS_STACK_LL_H
#define CDS_STACK_LL_H

#include<stdlib.h>
#include<stdio.h>

typedef struct stdStackNode stackNode;

struct stdStackNode{
    int data;
    stackNode* next;
};

typedef struct stdStack cstack;

struct stdStack {
     stackNode* top;
};

//static stackNode* CDS_Stack_createNode(int data);

cstack* CDS_StackLL_init();

void CDS_StackLL_push(cstack* stack,int data);
void CDS_StackLL_pop(cstack* stack);
stackNode* CDS_StackLL_top(cstack* stack);
int CDS_StackLL_isEmpty(cstack* stack);
void CDS_StackLL_destroy(cstack* stack);

#endif // CDS_STACK_LL_H
