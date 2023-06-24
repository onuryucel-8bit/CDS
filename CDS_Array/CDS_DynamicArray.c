#include "CDS_DynamicArray.h"

//TODO void CDS_dynamicArray_removeElement(cdst_array* array,void* data) add resize code

//21.05.23 tested
static cdst_array_Data* createArrayData(unsigned int size){
    cdst_array_Data* newData = malloc(sizeof(cdst_array_Data) * size);

    if(newData == NULL){
        return NULL;
    }

    for(int i = 0; i < size;i++){
        newData[i].data = NULL;
    }

    return newData;
}

//21.05.23 tested
cdst_array* CDS_dynamicArray_init(unsigned int capacity){

    cdst_array* newArray = malloc(sizeof(cdst_array));

    if(newArray == NULL){
        return NULL;
    }

    newArray->arrayHead = createArrayData(capacity);
    newArray->capacity = capacity;
    newArray->index = 0;

    return newArray;
}

//-----------------------------------------------------------//
//----------------ADD----------------//
//-----------------------------------------------------------//

//21.05.23 tested
void CDS_dynamicArray_addLast(cdst_array* array,void* data){

    if(array == NULL || array->arrayHead == NULL) return;

    //if array is full, resize the array
    if(array->index >= array->capacity){
        CDS_dynamicArray_resize();
    }

    //put data to end of the array
    array->arrayHead[array->index].data = data;

    array->index++;
}

//-----------------------------------------------------------//
//--------------REMOVE---------------//
//-----------------------------------------------------------//

/**
*  remove last element
*/
void CDS_dynamicArray_removeElement(cdst_array* array,void* data){

    if(array == NULL || array->arrayHead == NULL)
        return;

    if(array->index == 0){
        return;
    }

    //resize code here

    array->arrayHead[array->index].data = NULL;
    array->index--;
}


/**
*   array[i] = NULL
*/
void CDS_dynamicArray_removeElementIndex(cdst_array* array,void* data,unsigned int index){

    if(array == NULL || array->arrayHead == NULL) return;

    if(array->index - 1 <= index){
        return;
    }

    for(int i = index - 1;i < array->index - 1; i++){
        array->arrayHead[i].data = array->arrayHead[i + 1].data;
    }

    //resize code here
}

//-----------------------------------------------------------//
//---------------UTILS---------------//
//-----------------------------------------------------------//

/**
*   array[i]
*/
void* CDS_dynamicArray_getElement(cdst_array* array,unsigned int index){

    if(array == NULL || array->arrayHead == NULL) return NULL;

    if(array->index <= index){
        return NULL;
    }
    return array->arrayHead[index].data;
}


/**
*   if findData inside of array return 1;
*   else return 0;
*/
int CDS_dynamicArray_searchElement(cdst_array* array,void* findData,int compare(void* element1,void* element2)){

    if(array == NULL || array->arrayHead == NULL) return NULL;

    //if array is empty return ZERO
    if(array->index <= 0){
        return 0;//false
    }

    //search element inside of array
    //if element inside of array then return true

    for(int i = 0; i < array->index;i++){
        if(compare(array->arrayHead[i].data,findData)){
            return 1;//true
        }
    }

    return 0;//false

}

/**
*   if findData inside of array return index of findData
*   else return -1
*/
int  CDS_dynamicArray_getIndex(cdst_array* array,void* findData,int compare(void* element1,void* element2)){

    if(array == NULL || array->arrayHead == NULL) return NULL;

    //if array is empty return NEGATIVE ONE
    if(array->index <= 0){
        return -1;
    }

    for(int i = 0; i < array->index; i++){
        if(compare(array->arrayHead[i].data,findData)){
            return i;
        }
    }

    return -1;
}

/**
*   if findData inside of array return pointer of findData
*   else return NULL
*/
void* CDS_dynamicArray_findElement(cdst_array* array,void* findData,int compare(void* element1,void* element2)){

    if(array == NULL || array->arrayHead == NULL) return NULL;

    if(array->index <= 0){
        return NULL;
    }

    for(int i = 0; i < array->index; i++){
        if(compare(array->arrayHead[i].data,findData)){
            return array->arrayHead[i].data;
        }
    }
    return NULL;
}

void  CDS_dynamicArray_sort(cdst_array* array,int compare(void* fdata,void* sdata)){

    if(array == NULL || array->arrayHead == NULL) return;

    if(array->index <= 0){
        return;
    }

    for(int i = 0; i < array->index; i++){
        if(compare(array->arrayHead[i].data,array->arrayHead[i+1].data)){
            //code here
        }
    }
}

/**
*  makes all element equal to zero
*/
void  CDS_dynamicArray_clearAll(cdst_array* array){

    if(array == NULL || array->arrayHead == NULL)
        return;

    for(int i = 0; i < array->capacity; i++){
        array->arrayHead[i].data = 0;
    }

}

void  CDS_dynamicArray_resize(cdst_array* array){
     cdst_array* newArray = CDS_init_dynamicArray(array->capacity + 10);

     for(int i = 0; i < array->index; i++){
        newArray->arrayHead[i].data = array->arrayHead[i].data;
     }

     CDS_destroy_dynamicArray(array);

     array = newArray;
}

//21.05.23
void  CDS_destroy_dynamicArray(cdst_array* dataPack){

   if(dataPack == NULL) return;

    //dataPack->index = 0;
   for(int i = 0; i < dataPack->capacity; i++){
        free(dataPack->arrayHead[i].data);
   }

   free(dataPack->arrayHead);
   free(dataPack);

   dataPack->arrayHead = NULL;
   dataPack->capacity = 0;

}
