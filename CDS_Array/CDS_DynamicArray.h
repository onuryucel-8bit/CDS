#ifndef CDS_DYNAMIC_ARRAY_H
#define CDS_DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>

typedef struct stdDataCell cdst_array_Data;

struct stdDataCell{
    void* data;
};

typedef struct stdDynamicArray cdst_array;

struct stdDynamicArray{

    cdst_array_Data* arrayHead;
    unsigned int index;
    unsigned int capacity;
};

cdst_array* CDS_dynamicArray_init(unsigned int capacity);

//----------------ADD----------------//
void CDS_dynamicArray_addLast(cdst_array* array,void* data);
void CDS_dynamicArray_addIndex(cdst_array* array,void* data,unsigned int index);

//--------------REMOVE---------------//
void CDS_dynamicArray_removeElement(cdst_array* array,void* data);
void CDS_dynamicArray_removeElementIndex(cdst_array* array,void* data,unsigned int index);

//---------------UTILS---------------//

void* CDS_dynamicArray_getElement(cdst_array* array,unsigned int index);
int   CDS_dynamicArray_getIndex(cdst_array* array,void* data,int compare(void* element1,void* element2));
int CDS_dynamicArray_searchElement(cdst_array* array,void* findData,int compare(void* element1,void* element2));

//transforms default array to CDS dynamic arrays
//void  CDS_dynamicArray_transformTo_darray(cdst_dynamic_Array* array,unsigned int size);

//void  CDS_dynamicArray_findMax(cdst_dynamic_Array* array,int compare(void* data1, void* data2));
//void  CDS_dynamicArray_findMin(cdst_dynamic_Array* array,int compare(void* data1, void* data2));

void  CDS_dynamicArray_destroy(cdst_array* dataPack);


#endif
