#ifndef CDS_DYNAMIC_ARRAY_H
#define CDS_DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>

#define DEBUG 1

//TODO add find min,max value func
//TODO resize func
//TODO addIndex func
//TODO removeIndex func
//TODO sort func

typedef struct stdDataCell cdst_array_Data;

struct stdDataCell{
    void* data;
};

typedef struct stdDynamicArray cdst_array;

struct stdDynamicArray{

    cdst_array_Data* arrayHead;
    unsigned int index;
    unsigned int capacity;
    char statusFlag;
};

cdst_array* CDS_dynamicArray_init(unsigned int capacity);

//----------------ADD----------------//

void CDS_dynamicArray_addLast(cdst_array* array,void* data);

//--------------REMOVE---------------//

void CDS_dynamicArray_removeElement(cdst_array* array,void* data);

//---------------UTILS---------------//

//return a[i]
void* CDS_dynamicArray_getElement_byIndex(cdst_array* array,unsigned int index);

//return i
int CDS_dynamicArray_searchElement(cdst_array* array,void* findData,int compare(void* element1,void* element2));

cdst_array_Data* CDS_dynamicArray_getLastElement(cdst_array* array);

void CDS_dynamicArray_test_print(cdst_array* array);

void* CDS_dynamicArray_findElement(cdst_array* array,void* findData,int compare(void* element1,void* element2));

void  CDS_dynamicArray_resize(cdst_array** array,char up_down);

void  CDS_dynamicArray_sort(cdst_array* array,int compare(void* fdata,void* sdata));

void  CDS_dynamicArray_destroy(cdst_array* dataPack);


#endif
