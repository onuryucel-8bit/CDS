//tested without compare function 28.06.23
#ifndef CDS_STACK_LL_H
#define CDS_STACK_LL_H

#include<stdlib.h>
#include<stdio.h>

#include"../CDS_generalData/allocationEnumData.h"

///TODO stack compare functions 11.06.23

typedef struct stdStack_Node cdst_stack_Data;

struct stdStack_Node{
    void* data;
    cdst_stack_Data* next;
};

typedef struct stdStack cdst_stack_Holder;

struct stdStack {
     cdst_stack_Data* top;
     char type;
};

//----------------------------------------------------------------//

cdst_stack_Holder* CDS_stack_lil_init(enum cdsMemoryType type);

void CDS_stack_lil_push(cdst_stack_Holder* stack,void* data);

void CDS_stack_lil_pop(cdst_stack_Holder* stack);

//----------------------------------------------------------------//

void* CDS_stack_lil_top(cdst_stack_Holder* stack);

int CDS_stack_lil_isEmpty(cdst_stack_Holder* stack);

void CDS_StackLL_compare(cdst_stack_Holder* stack,cdst_stack_Holder* cmpStack,int compare(void* data1,void* data2));

char CDS_StackLL_getType_char_Top(cdst_stack_Holder* stack);

int CDS_StackLL_getType_int_Top(cdst_stack_Holder* stack);

void CDS_stack_lil_destroy(cdst_stack_Holder* stack);

#endif // CDS_STACK_LL_H
