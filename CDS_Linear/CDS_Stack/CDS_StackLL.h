#ifndef CDS_STACK_LL_H
#define CDS_STACK_LL_H

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>


typedef struct stdStack_Node cdst_stack_Data;

struct stdStack_Node{
    void* data;
    cdst_stack_Data* next;
};

typedef struct stdStack cdst_stack_Holder;

struct stdStack {
     cdst_stack_Data* top;
};

//static stackNode* CDS_Stack_createNode(int data);

cdst_stack_Holder* CDS_StackLL_init();

void CDS_StackLL_push(cdst_stack_Holder* stack,void* data);

void CDS_StackLL_pop(cdst_stack_Holder* stack);

cdst_stack_Data* CDS_StackLL_top(cdst_stack_Holder* stack);

int CDS_StackLL_isEmpty(cdst_stack_Holder* stack);

void CDS_StackLL_destroy(cdst_stack_Holder* stack);

#endif // CDS_STACK_LL_H
