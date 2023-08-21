#ifndef CDS_STACK_ARRAY_H
#define CDS_STACK_ARRAY_H

#include<stdlib.h>


void CDS_stack_array_push(cdst_array* stack, void* data);

void CDS_stack_array_pop(cdst_array* stack);

void* CDS_stack_array_getTop();

int CDS_stack_array_isEmpty(cdst_array* stack);

void CDS_stack_array_destroy();

#endif
