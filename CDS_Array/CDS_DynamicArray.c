#include "CDS_DynamicArray.h"
/*

cdsArrayData* CDS_da_init(){

    cdsArrayData dataPack;
    cdsArrayData* returnPointer = &dataPack;

    dataPack.CDS_array_index = 0;
    dataPack.CDS_array_size = 5;
    dataPack.CDS_array = (int*)malloc(5 * sizeof(int));

    return returnPointer;
}

cdsArrayData* CDS_da_init() {

    arrayDataPack* dataPack = malloc(sizeof(arrayDataPack));

    if (dataPack == NULL) {
        // handle error if malloc fails
        printf("Error: unable to allocate memory\n");
        exit(1);
    }

    dataPack->CDS_array_index = 0;
    dataPack->CDS_array_size = 5;
    dataPack->CDS_array = malloc(5 * sizeof(int));

    if (dataPack->CDS_array == NULL) {
        // handle error if malloc fails
        printf("Error: unable to allocate memory\n");
        exit(1);
    }
    return dataPack;
}


void CDS_da_addElement(int element,cdsArrayData* dataPack){

   if (dataPack->CDS_array_index >= dataPack->CDS_array_size) {
        // the array is full, so we cannot add any more elements
        printf("Error: array is full\n");
        return;
    }
    dataPack->CDS_array[dataPack->CDS_array_index] = element;
    dataPack->CDS_array_index++;

}

void CDS_da_removeElement(int element,cdsArrayData* dataPack){

    if(dataPack->CDS_array_index == 0) return;

    dataPack->CDS_array_index--;
}

void CDS_da_free(cdsArrayData* dataPack){

    free(dataPack->CDS_array);
}

void CDS_da_clear(cdsArrayData* dataPack){

    dataPack->CDS_array_index = 0;
}
*/
