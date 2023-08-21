#ifndef CDS_DYNAMIC_ARRAY_H
#define CDS_DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>

#define CDS_FALSE 0
#define CDS_TRUE 1

#define DEBUG 1
#define DEBUG_SHIFT_RIGHT_CAPS

#define DEBUG_SHIFT_RIGHT_CAPE 1

#define DEFAULT_RESIZE_AMOUNT 5

#include"../CDS_generalData/allocationEnumData.h"

//TODO fix: destroy for heap

typedef struct std_cds_DynamicArray cdst_array;

struct std_cds_DynamicArray{

    void* head;
    unsigned int index;
    unsigned int capacity;
    size_t resize_amount;
    char type;
};
//,size_t resize_amount
cdst_array* CDS_dynamicArray_init(size_t capacity,enum cdsMemoryType type);

//----------------ADD----------------//

void CDS_dynamicArray_addIndex(cdst_array* array,size_t index,void* data);

void CDS_dynamicArray_addLast(cdst_array* array,void* data);

//--------------REMOVE---------------//

void CDS_dynamicArray_removeLast(cdst_array* array);

void CDS_dynamicArray_removeIndex(cdst_array* array,size_t index);

//---------------UTILS---------------//

//return a[i]
void* CDS_dynamicArray_getElement_byIndex(cdst_array* array,unsigned int index);

//return i
int CDS_dynamicArray_searchElement(cdst_array* array,void* findData,int compare(void* element1,void* element2));

//return object
void* CDS_dynamicArray_getLastElement(cdst_array* array);

void CDS_dynamicArray_test_print(cdst_array* array);

//return object
void* CDS_dynamicArray_findElement(cdst_array* array,void* findData,int compare(void* element1,void* element2));

void  CDS_dynamicArray_sort(cdst_array* array,int compare( void* fdata, void* sdata));

//array[i] = data
void CDS_dynamicArray_changeData(cdst_array* array,size_t index,void* data);

int CDS_dynamicArray_isEmpty(cdst_array* array);

void CDS_dynamicArray_changeType(cdst_array* array,enum cdsMemoryType type);

void CDS_dynamicArray_clear(cdst_array* array);

void  CDS_dynamicArray_destroy(cdst_array* dataPack);


#endif
