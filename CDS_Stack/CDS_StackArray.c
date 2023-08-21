#include "CDS_StackLL.h"

#include "../CDS_Array/CDS_DynamicArray.h"

void CDS_stack_array_push(cdst_array* stack, void* data){
    CDS_dynamicArray_addLast(stack,data);
}

void CDS_stack_array_pop(cdst_array* stack){
    CDS_dynamicArray_removeLast(stack);
}

void* CDS_stack_array_getTop(cdst_array* stack){
    return CDS_dynamicArray_getLastElement(stack);
}

int CDS_stack_array_isEmpty(cdst_array* stack){
    return CDS_dynamicArray_isEmpty(stack);
}

void CDS_stack_array_destroy(){
}
