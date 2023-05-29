#ifndef CDS_STACK_ARRAY_H
#define CDS_STACK_ARRAY_H

#include<stdlib.h>

typedef struct stdStackArrayData cds_stackArrData;

struct stdStackArrayData{
    void* data;
};

typedef struct stdStackArray cds_stackArray;

struct stdStackArray{
    cds_stackArrData* array;
    unsigned int capacity;
    unsigned int index;
};

cds_stackArray* CDS_Stack_arr_init(unsigned int capacity);

void CDS_Stack_arr_push(cds_stackArray* stack,void* data);

void CDS_Stack_arr_pop(cds_stackArray* stack);

//----------------------------------------------------//

cds_stackArrData* CDS_Stack_arr_top(cds_stackArray* stack);

int CDS_Stack_arr_isEmpty(cds_stackArray* stack);

void CDS_Stack_arr_destroy(cds_stackArray* stack);

#endif
