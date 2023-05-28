#ifndef CDS_STACK_ARRAY_H
#define CDS_STACK_ARRAY_H

#include<stdlib.h>

typedef struct stdStackArrayData stackArrData;

struct stdStackArrayData{
    void* data;
};

typedef struct stdStackArray stackArray;

struct stdStackArray{
    stackArrData* top;
    unsigned int capacity;
    unsigned int index;
};

stackArray* CDS_Stack_arr_init(unsigned int capacity);

void CDS_Stack_arr_push(stackArray* stack,int data);
void CDS_Stack_arr_pop(stackArray* stack);
stackArrData* CDS_Stack_arr_top(stackArray* stack);
int CDS_Stack_arr_isEmpty(stackArray* stack);
void CDS_Stack_arr_destroy(stackArray* stack);

#endif
