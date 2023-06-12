#include "CDS_StackArray.h"

//29.05.23
static cds_stackArrData* createStackData(unsigned int size){
     cds_stackArrData* newArrayofDatas = malloc(sizeof(cds_stackArrData));

     if(newArrayofDatas == NULL)
        return 0;

     return newArrayofDatas;
}

//29.05.23
cds_stackArray* CDS_Stack_arr_init(unsigned int capacity){
     cds_stackArray* newStack = malloc(sizeof(cds_stackArray));

     if(newStack == NULL)
        return 0;

     newStack->capacity = capacity;
     newStack->index = 0;
     newStack->array = createStackData(capacity);


     return newStack;
}

//29.05.23
//pushs element to stack array if stack or stack.array null then returns 0
void CDS_Stack_arr_push(cds_stackArray* stack,void* data){
    if(stack == NULL || stack->array == NULL)
      return;

    if(stack->index >= stack->capacity){
        //resize code here
    }

    stack->array[stack->index].data = data;

    stack->index++;

}

//29.05.23
///pops the top element if stack or stack.array is null then return
//if stack->index <= 0 then return
void CDS_Stack_arr_pop(cds_stackArray* stack){
    if(stack->index <= 0 || stack == NULL || stack->array == NULL)
      return;

    //resize
    //if(stack->capacity - stack->index + 1 ){
    //    return;
    //}

    //stack->array->data = 0;
    stack->index--;

}

//29.05.23
cds_stackArrData* CDS_Stack_arr_top(cds_stackArray* stack){

    if(stack->index == 0 || stack == NULL || stack->array == NULL){
        return 0;
    }

    return stack->array[stack->index - 1].data;
}

//29.05.23
///if empty => 1 else => 0
int CDS_Stack_arr_isEmpty(cds_stackArray* stack){
    if(stack->array == NULL)
        return 1;

    return 0;
}

//29.05.23
void CDS_Stack_arr_destroy(cds_stackArray* stack){

   for(int i = 0; i < stack->capacity; i++){
        free(stack->array[i].data);
   }

   free(stack);
   free(stack->array);

   stack = NULL;

}
