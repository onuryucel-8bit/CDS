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
    unsigned int capacity;
};

cdsArray* CDS_dynamicArray_init(unsigned int capacity);

//----------------ADD----------------//
void CDS_dynamicArray_addLast(cdsArray* array,void* data);
void CDS_dynamicArray_addIndex(cdsArray* array,void* data,unsigned int index);

//--------------REMOVE---------------//
void CDS_dynamicArray_removeElement(cdsArray* array,void* data);
void CDS_dynamicArray_removeElementIndex(cdsArray* array,void* data,unsigned int index);

//---------------UTILS---------------//

void* CDS_dynamicArray_getElement(cdsArray* array,unsigned int index);
int   CDS_dynamicArray_searchIndex(cdsArray* array,void* data,int compare(void* element1,void* element2));
int   CDS_dynamicArray_searchElement();
void* CDS_dynamicArray_findElement();

void  CDS_dynamicArray_sort();

void  CDS_dynamicArray_clearAll(cdsArray* array);
void  CDS_dynamicArray_resize();

//transforms default array to CDS dynamic arrays
//void  CDS_dynamicArray_transformTo_darray(cdst_dynamic_Array* array,unsigned int size);

//void  CDS_dynamicArray_findMax(cdst_dynamic_Array* array,int compare(void* data1, void* data2));
//void  CDS_dynamicArray_findMin(cdst_dynamic_Array* array,int compare(void* data1, void* data2));

void  CDS_dynamicArray_free(cdsArray* dataPack);


#endif
