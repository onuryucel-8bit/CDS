#include "CDS_DynamicArray.h"

//21.05.23 tested
cdst_array_Data* createArrayData(unsigned int size){

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
    newArray->statusFlag = 1;

    return newArray;
}

//----------------ADD----------------//

//21.05.23 tested
void CDS_dynamicArray_addLast(cdst_array* array,void* data){

    if(array == NULL || array->arrayHead == NULL) return;

    array->statusFlag = 1;

    //if array is full, resize the array
    if(array->index >= array->capacity){
        CDS_dynamicArray_resize(&array,1);
        #if DEBUG
            printf("DEBUG: %i index %i capacity \n",array->index,array->capacity);
            printf("array ptr %p \n",array);
        #endif // DEBUG
    }

    //put data to end of the array
    array->arrayHead[array->index].data = data;

    array->index++;
}

//--------------REMOVE---------------//

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

//---------------UTILS---------------//

/**
*   array[i]
*/
void* CDS_dynamicArray_getElement_byIndex(cdst_array* array,unsigned int index){

    if(array == NULL || array->arrayHead == NULL) return NULL;

    if(array->index <= index){
        return NULL;
    }
    return array->arrayHead[index].data;
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

cdst_array_Data* CDS_dynamicArray_getLastElement(cdst_array* array){
    if(array == NULL)return NULL;

    return array->arrayHead[array->index - 1].data;
}

void CDS_dynamicArray_test_print(cdst_array* array){

    if(array == NULL || array->arrayHead == NULL || array->statusFlag == 0)return;

    for(int i = 0; i < array->index; i++){
        printf("%i \n", *(int*)(array->arrayHead[i].data));
    }
}

/**
*   char: up_down
*     if up_down == 1 resize up
*     else resize down
*
*/
void  CDS_dynamicArray_resize(cdst_array** array,char up_down){


    cdst_array* oldArray = *array;

    //create new array
    cdst_array* newArray = NULL;
    if(up_down)
        newArray = CDS_dynamicArray_init(oldArray->capacity + 5);
    else
        newArray = CDS_dynamicArray_init(oldArray->capacity);

    printf("new Array cap %i",newArray->capacity);
    //copy data to new Array
    for(int i = 0; i < oldArray->index; i++){

        newArray->arrayHead[i].data = oldArray->arrayHead[i].data;
    }

    #if DEBUG
        printf("copying data DONE\n");
    #endif // DEBUG

    /*//destroy old one
    for(int i = 0; i < array->capacity; i++){
        free(array->arrayHead[i].data);
    }

    free(array->arrayHead);
*/
    newArray->statusFlag = 1;
    newArray->index = oldArray->index;

    //change pointer
    printf("newArray ptr %p \n",newArray);
    printf("Array    ptr %p \n",array);
    *array = newArray;
    printf("Array   cptr %p \n",array);
}

/**
*  DEFINE COMPARE FUNC: (void*,void*)
*  if findData > array.data   return 1
*  else if findData <= array.data return 0
*
*/
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

//21.05.23
void  CDS_dynamicArray_destroy(cdst_array* dataPack){

   if(dataPack == NULL || dataPack->arrayHead == NULL || dataPack->statusFlag == 0) return;

    //dataPack->index = 0;
   for(int i = 0; i < dataPack->capacity; i++){
        free(dataPack->arrayHead[i].data);
   }

   free(dataPack->arrayHead);
   free(dataPack);

   dataPack->arrayHead = NULL;
   dataPack->capacity = 0;

}
