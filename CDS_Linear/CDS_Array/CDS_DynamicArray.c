#include "CDS_DynamicArray.h"

//21.05.23 tested
static cdsArray_Data* createArrayData(unsigned int size){
    cdsArray_Data* newData = malloc(sizeof(cdsArray_Data) * size);

    if(newData == NULL){
        return NULL;
    }

    for(int i = 0; i < size;i++){
        newData[i].data = NULL;
    }

    return newData;
}

//21.05.23 tested
cdsArray* CDS_dynamicArray_init(unsigned int capacity){

    cdsArray* newArray = malloc(sizeof(cdsArray));

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
void CDS_dynamicArray_addLast(cdsArray* array,void* data){

    //if array is full resize the array
    if(array->index >= array->capacity){
        CDS_dynamicArray_resize();
    }

    /*  simple represantition of code
    *
    *   struct Points* array = malloc(sizeof(struct Points) * n);
    *   array[i].x = newx_value;
    *
    */
    array->arrayHead[array->index].data = data;

    array->index++;
}

//change name to overWrite
void CDS_dynamicArray_addIndex(cdsArray* array,void* data,unsigned int index){
    if(array->index <= index){
        return;
    }

    array->arrayHead[index].data = data;
}

//-----------------------------------------------------------//
//--------------REMOVE---------------//
//-----------------------------------------------------------//

void CDS_dynamicArray_removeElement(cdsArray* array,void* data){

    if(array->index == 0){
        return;
    }

    array->arrayHead[array->index].data = NULL;
    array->index--;
}

void CDS_dynamicArray_removeElementIndex(cdsArray* array,void* data,unsigned int index){
    if(array->index - 1 <= index){
        return;
    }

    for(int i = index - 1;i < array->index - 1; i++){
        array->arrayHead[i].data = array->arrayHead[i + 1].data;
    }
}

//-----------------------------------------------------------//
//---------------UTILS---------------//
//-----------------------------------------------------------//

void* CDS_dynamicArray_getElement(cdsArray* array,unsigned int index){
    if(array->index <= index){
        return NULL;
    }
    return array->arrayHead[index].data;
}

int CDS_dynamicArray_searchElement(cdsArray* array,void* findData,int compare(void* element1,void* element2)){

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

int  CDS_dynamicArray_searchIndex(cdsArray* array,void* findData,int compare(void* element1,void* element2)){

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

void* CDS_dynamicArray_findElement(cdsArray* array,void* findData,int compare(void* element1,void* element2)){
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

void  CDS_dynamicArray_sort(cdsArray* array,int compare(void* fdata,void* sdata)){
    if(array->index <= 0){
        return;
    }

    for(int i = 0; i < array->index; i++){
        if(compare(array->arrayHead[i].data,array->arrayHead[i+1].data)){
            //code here
        }
    }
}

void  CDS_dynamicArray_clearAll(cdsArray* array){

}

void  CDS_dynamicArray_resize(cdsArray* array){
     cdsArray* newArray = CDS_dynamicArray_init(array->capacity + 10);

     for(int i = 0; i < array->index; i++){
        newArray->arrayHead[i].data = array->arrayHead[i].data;
     }

     CDS_dynamicArray_free(array);

     array = newArray;
}

//21.05.23 looks good
void  CDS_dynamicArray_free(cdsArray* dataPack){

   for(int i = 0; i < dataPack->capacity; i++){
        free(dataPack->arrayHead[i].data);
   }

   free(dataPack->arrayHead);
   free(dataPack);

   dataPack->arrayHead = NULL;
   dataPack->capacity = 0;
   dataPack->index = 0;
}
