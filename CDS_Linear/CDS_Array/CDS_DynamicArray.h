#ifndef CDS_DYNAMIC_ARRAY_H
#define CDS_DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>

typedef struct stdDataCell cdsArray_Data;

struct stdDataCell{
    void* data;
};

typedef struct stdDynamicArray cdsArray;

struct stdDynamicArray{

    cdsArray_Data* arrayHead;
    unsigned int index;

};

cdsArray* CDS_dynamicArray_init();

//----------------ADD----------------//
void CDS_dynamicArray_addLast(cdsArray* array,void* data);
void CDS_dynamicArray_addIndex(cdsArray* array,void* data,unsigned int index);

//--------------REMOVE---------------//
void CDS_dynamicArray_removeElement(cdsArray* array,void* data);
void CDS_dynamicArray_removeElementIndex(cdsArray* array,void* data);

//---------------UTILS---------------//

void* CDS_dynamicArray_getElement();
int   CDS_dynamicArray_searchElement();
void* CDS_dynamicArray_findElement();
void  CDS_dynamicArray_sort();
void  CDS_dynamicArray_clearAll(cdsArray* dataPack);
void  CDS_dynamicArray_resize();

void  CDS_dynamicArray_free(cdsArray* dataPack);


#endif
