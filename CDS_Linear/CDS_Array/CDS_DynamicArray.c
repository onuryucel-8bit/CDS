#include "CDS_DynamicArray.h"

cdsArray* CDS_dynamicArray_init(unsigned int size){

    cdsArray* newArray = malloc(sizeof(cdsArray));

    newArray->arrayHead = NULL;
    newArray->index = 0;

    return newArray;
}

static cdsArray_Data* createArrayData(void* data){
    cdsArray_Data* newData = malloc(sizeof(cdsArray_Data));

    newData->data = NULL;

    return newData;
}

//----------------ADD----------------//
void CDS_dynamicArray_addLast(cdsArray* array,void* data){

}
void CDS_dynamicArray_addIndex(cdsArray* array,void* data,unsigned int index){}

//--------------REMOVE---------------//
void CDS_dynamicArray_removeElement(cdsArray* array,void* data){}
void CDS_dynamicArray_removeElementIndex(cdsArray* array,void* data){}

//---------------UTILS---------------//

void* CDS_dynamicArray_getElement(){return 0;}
int   CDS_dynamicArray_searchElement(){return 0;}
void* CDS_dynamicArray_findElement(){return 0;}
void  CDS_dynamicArray_sort(){}
void  CDS_dynamicArray_clearAll(cdsArray* dataPack){}
void  CDS_dynamicArray_resize(){}

void  CDS_dynamicArray_free(cdsArray* dataPack){}
