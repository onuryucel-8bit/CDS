#include <stdio.h>

#include"CDS_DynamicArray.h"
#define PRINT CDS_dynamicArray_test_print(array);


int standart_int_sort_compare(void** data_1, void** data_2){
    int** a = (int**)data_1;
    int** b = (int**)data_2;

    if( *a > *b ) return 1;

    return 0;

}

int standart_int_compare(void* data_1, void* data_2){
    int* a = (int*)data_1;
    int* b = (int*)data_2;


    return *a == *b;
}

int main(){
/*
    int test = 36;
    void* heapDataPointer = &test;
    void* arrayCell = &heapDataPointer;
    void* array = &arrayCell;


    printf("array           %p \n",array);
    printf("arrayCell       %p \n",arrayCell);
    printf("heapDataPointer %p \n",heapDataPointer);
    printf("&test           %p \n",&test);
*/
    cdst_array* array = CDS_dynamicArray_init(5,CDS_HEAP_ALLOCATE);

    printf("array head %p \n",array->head);

    int* dizi = (int*)malloc(5 * sizeof(int));
    dizi[0] = 2;
    dizi[1] = 45;
    dizi[2] = 75;
    dizi[3] = 56;
    dizi[4] = 32;

    //ADD LAST(INT ARRAY[5])
    for(int i = 0; i < 5; i++){
        CDS_dynamicArray_addLast(array,&dizi[i]);
    }

    printf("array[0] %p \n",((void**)array->head)[0]);

    //------//
    //PRINT

    //ADD LAST(INT 23);
    int* test_int_addLast = (int*) malloc(sizeof(int));
    *test_int_addLast = 23;

    CDS_dynamicArray_addLast(array,test_int_addLast);

    printf("ADD LAST(INT 23)\n");
    //------//
   // PRINT

    CDS_dynamicArray_sort(array,standart_int_sort_compare);

    printf("SORT \n");
    //------//
    PRINT

    //CDS_dynamicArray_addLast(array,test_int_addLast);
    //CDS_dynamicArray_addLast(array,(void*)test_int_addLast);

    //this works too

    //void* test = malloc(sizeof(int));
    //*(int*)(test) = 23;

    //CDS_dynamicArray_addLast(array,test);

    printf("array                       %p \n", array);
    printf("array->head                 %p \n", array->head);
    printf("((void**)(array->head) )[0] %p \n", ((void**)(array->head) )[0]);



    printf("--------CDS_DESTROY-----------\n");
    CDS_dynamicArray_destroy(array);



}
