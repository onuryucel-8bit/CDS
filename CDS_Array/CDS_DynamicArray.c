#include "CDS_DynamicArray.h"

cdst_array* CDS_dynamicArray_init(size_t capacity){

    cdst_array* newArray = malloc(sizeof(cdst_array));

    if(newArray == NULL){
        return NULL;
    }

    newArray->head = malloc(sizeof(void*) * capacity);
    for(int i = 0; i < capacity; i++){
          //convert void pointer to .pointer to pointer
        ( (void**)(newArray->head) )[i] = NULL;
    }
    //check error
    if(newArray->head == NULL)return;

    newArray->capacity = capacity;
    newArray->index = 0;
    newArray->statusFlag = 1;

    return newArray;
}

//----------------ADD----------------//

void CDS_dynamicArray_addLast(cdst_array* array,void* data){
    ((void**)(array->head))[array->index] = data;
    array->index ++;
}

//--------------REMOVE---------------//

/**
*  remove last element
*/
void CDS_dynamicArray_removeElement(cdst_array* array,void* data){

}

//---------------UTILS---------------//

/**
*   array[i]
*/
void* CDS_dynamicArray_getElement_byIndex(cdst_array* array,unsigned int index){

}

/**
*   if findData inside of array return 1;
*   else return 0;
*
*   DEFINE FUNCTION : COMPARE(void*,void*)
*   if(a==b)return 1
*   return 0
*/
int CDS_dynamicArray_searchElement(cdst_array* array,void* findData,int compare(void* element1,void* element2)){

}

/**
*   if findData inside of array return pointer of findData
*   else return NULL
*/
void* CDS_dynamicArray_findElement(cdst_array* array,void* findData,int compare(void* element1,void* element2)){

}

void* CDS_dynamicArray_getLastElement(cdst_array* array){

}

void CDS_dynamicArray_test_print(cdst_array* array){
    for(int i = 0; i < array->index;i++){
        int* element = ((int**)(array->head))[i];
        printf("%i \n",*(((int**)(array->head))[i]));
    }
}

/**
*   char: up_down
*     if up_down == 1 resize up
*     else resize down
*
*/
void  CDS_dynamicArray_resize(cdst_array** array,char up_down){


}

/**
*  DEFINE COMPARE FUNC: (void*,void*)
*  if findData > array.data   return 1
*  else if findData <= array.data return 0
*
*/
void  CDS_dynamicArray_sort(cdst_array* array,int compare(void* fdata,void* sdata)){

}

void  CDS_dynamicArray_destroy(cdst_array* array){

    free(array->head);
    free(array);
}
