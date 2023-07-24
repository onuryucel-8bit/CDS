#ifndef CDS_DYNAMIC_ARRAY_H
#define CDS_DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>

//TODO addIndex func
//TODO removeIndex func

typedef struct std_cds_DynamicArray cdst_array;

struct std_cds_DynamicArray{

    void* head;
    unsigned int index;
    unsigned int capacity;
    char statusFlag;
};

cdst_array* CDS_dynamicArray_init(size_t capacity);

//----------------ADD----------------//

void CDS_dynamicArray_addIndex(cdst_array* array,size_t index,void* data);

void CDS_dynamicArray_addLast(cdst_array* array,void* data);

//--------------REMOVE---------------//

void CDS_dynamicArray_removeLast(cdst_array* array);

//---------------UTILS---------------//

//return a[i]
void* CDS_dynamicArray_getElement_byIndex(cdst_array* array,unsigned int index);

//return i
int CDS_dynamicArray_searchElement(cdst_array* array,void* findData,int compare(void* element1,void* element2));

void* CDS_dynamicArray_getLastElement(cdst_array* array);

void CDS_dynamicArray_test_print(cdst_array* array);

void* CDS_dynamicArray_findElement(cdst_array* array,void* findData,int compare(void* element1,void* element2));

void  CDS_dynamicArray_sort(cdst_array* array,int compare( void* fdata, void* sdata));

void CDS_dynamicArray_changeData(cdst_array* array,size_t index,void* data);

static void sta_dynamic_array_shiftRight(cdst_array* array, size_t index);

void  CDS_dynamicArray_destroy(cdst_array* dataPack);


#endif
