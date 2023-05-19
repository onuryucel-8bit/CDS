#ifndef CDS_DYNAMIC_ARRAY_H
#define CDS_DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>

typedef struct CDSdynamicArray cdsArray;

struct CDSdynamicArray{
    int* CDS_array;
    int  CDS_array_index;
};

typedef struct arrayDataPack cdsArrayData;

struct arrayDataPack{
    cdsArray* array;
};

cdsArrayData* CDS_da_init();
void CDS_da_addElement(int element,cdsArrayData* dataPack,int size_ty);
void CDS_da_removeElement(int element,cdsArrayData* dataPack,int size_ty);

void CDS_da_findElement();
void CDS_da_sort();
void CDS_da_free(cdsArrayData* dataPack);
void CDS_da_clear(cdsArrayData* dataPack);
void CDS_da_resize();

#endif
