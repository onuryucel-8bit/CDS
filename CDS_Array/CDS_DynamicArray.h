#ifndef CDS_DYNAMIC_ARRAY_H
#define CDS_DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>

#define DEBUG 1
#define DEFAULT_RESIZE_AMOUNT 5

//check realloc, malloc errors if(malloc(s) == null) return

typedef struct std_cds_DynamicArray cdst_array;

struct std_cds_DynamicArray{

    void* head;
    unsigned int index;
    unsigned int capacity;
    size_t resize_amount;
};
//,size_t resize_amount
cdst_array* CDS_dynamicArray_init(size_t capacity);

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

void  CDS_dynamicArray_destroy(cdst_array* dataPack);


#endif
