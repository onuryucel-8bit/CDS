#include "CDS_DynamicArray.h"

cdst_array* CDS_dynamicArray_init(size_t capacity){

    cdst_array* newArray = malloc(sizeof(cdst_array));

    if(newArray == NULL){
        return NULL;
    }

    newArray->head = malloc(sizeof(void*) * capacity);
    //check error
    if(newArray->head == NULL)return NULL;
    
    for(int i = 0; i < capacity; i++){
          //convert void pointer to .pointer to pointer
        ( (void**)(newArray->head) )[i] = NULL;
    }
    

    newArray->capacity = capacity;
    newArray->index = 0;
    newArray->statusFlag = 1;

    return newArray;
}

//----------------ADD----------------//

/**
*  if index >= array.length addLast()
*  array[index] = data
*/
void CDS_dynamicArray_addIndex(cdst_array* array,size_t index,void* data){

    if(index >= array->index){
        CDS_dynamicArray_addLast(array,data);
        return;
    }

    ((void**)(array->head))[index] = data;
}

void CDS_dynamicArray_addLast(cdst_array* array,void* data){

    ((void**)(array->head))[array->index] = data;
    array->index ++;
}

//--------------REMOVE---------------//

/**
*  remove last element
*/
void CDS_dynamicArray_removeLast(cdst_array* array){
    ( (void**)(array->head) )[array->index - 1] = NULL;
    array->index --;
}

//---------------UTILS---------------//

/**
*   return array[i]
*/
void* CDS_dynamicArray_getElement_byIndex(cdst_array* array,unsigned int index){
    return ((void**)(array->head))[index];
}

/**
*   return array[index-1]
*/
void* CDS_dynamicArray_getLastElement(cdst_array* array){
    return ((void**)(array->head))[array->index - 1];
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

    //searching in array
    for(int i = 0; i < array->index; i++){
        //compare
        if(compare( ( (void**)(array->head) )[i]  , findData)  ){
            return 1;
        }
    }

    return 0;
}

/**
*   if findData inside of array return pointer of findData
*   else return NULL
*/
void* CDS_dynamicArray_findElement(cdst_array* array,void* findData,int compare(void* element1,void* element2)){

    //search in array
    for(int i = 0; i < array->index; i++){
        //compare
        if(compare( ((void**)(array->head) )[i]  , findData)  ){
            return ((void**)(array->head) )[i];
        }
    }

    return NULL;
}

void CDS_dynamicArray_test_print(cdst_array* array){
    for(int i = 0; i < array->index;i++){
        //int* element = ((int**)(array->head))[i];
        printf("%i ptr : %p \n",*(((int**)(array->head))[i]),(((int**)(array->head))[i]));

    }
    printf("*****\n");
}

/**
*  DEFINE COMPARE FUNC: (void*,void*)
*  if findData > array.data   return 1
*  else if findData <= array.data return 0
*
*  bubble_sort
*/
void  CDS_dynamicArray_sort(cdst_array* array,int compare(void* fdata,void* sdata)){

    void* temp = NULL;
    size_t size_arr = array->index;

    for(size_t i = 0;i < size_arr - 1; i++){

        for(size_t j = 0; j < size_arr - i - 1; j++){

            if(compare(((void**)(array->head) )[j] ,((void**)(array->head) )[j+1])){

                temp = ((void**)(array->head))[j];
                ((void**)(array->head) )[j] = ((void**)(array->head) )[j+1];
                ((void**)(array->head) )[j+1]= temp;

            }

        }//for j end

    }//for i end

}

void CDS_dynamicArray_changeData(cdst_array* array,size_t index,void* data){

    ((void**)(array->head))[index] = data;

}

void  CDS_dynamicArray_destroy(cdst_array* array){

    free(array->head);
    free(array);
}
