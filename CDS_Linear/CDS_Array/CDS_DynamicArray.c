#include "CDS_DynamicArray.h"

static cdsArray_Data* createArrayData(unsigned int size){
    cdsArray_Data* newData = malloc(sizeof(cdsArray_Data) * size);

    return newData;
}

cdsArray* CDS_dynamicArray_init(unsigned int capacity){

    cdsArray* newArray = malloc(sizeof(cdsArray));

    newArray->arrayHead = createArrayData(capacity);
    newArray->capacity = capacity;
    newArray->index = 0;

    return newArray;
}

//----------------ADD----------------//
void CDS_dynamicArray_addLast(cdsArray* array,void* data){

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

}
void CDS_dynamicArray_addIndex(cdsArray* array,void* data,unsigned int index){}

//--------------REMOVE---------------//
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

//---------------UTILS---------------//

void* CDS_dynamicArray_getElement(cdsArray* array,unsigned int index){
    if(array->index <= index){
        return NULL;
    }
    return array->arrayHead[index].data;
}

int   CDS_dynamicArray_searchElement(){return 0;}
void* CDS_dynamicArray_findElement(){return 0;}
void  CDS_dynamicArray_sort(){}
void  CDS_dynamicArray_clearAll(cdsArray* array){

}
void  CDS_dynamicArray_resize(){}

void  CDS_dynamicArray_free(cdsArray* dataPack){

    cdsArray_Data* current = dataPack->arrayHead;

    cdsArray_Data* nextNode = current;

    //free nodes
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    //free list
    free(dataPack);
    dataPack->head = NULL;
}
