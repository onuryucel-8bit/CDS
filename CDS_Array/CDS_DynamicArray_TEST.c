#include <stdio.h>
#include"CDS_DynamicArray.h"

int standart_int_sort_compare(void* data_1, void* data_2){
    int* a = (int*)data_1;
    int* b = (int*)data_2;

    if( *a > *b ) return 1;

    return 0;

}

int standart_int_compare(void* data_1, void* data_2){
    int* a = (int*)data_1;
    int* b = (int*)data_2;


    return *a == *b;
}

int main(){

    cdst_array* array = CDS_dynamicArray_init(5);

    int* a = (int*)malloc(5 * sizeof(int));
    a[0] = 2;
    a[1] = 45;
    a[2] = 75;
    a[3] = 56;
    a[4] = 32;
    for(int i = 0; i < 5; i++){
        CDS_dynamicArray_addLast(array,&a[i]);
    }

    //------//
    CDS_dynamicArray_test_print(array);

   /* int test_int_add = 10;
    printf("==== addLast 10 ==== \n");
    CDS_dynamicArray_addLast(array,&test_int_add);

    //------//
    CDS_dynamicArray_test_print(array);

    /*CDS_dynamicArray_sort(array,standart_int_compare);

    printf("==== removeLast 10 ==== \n");
    CDS_dynamicArray_removeLast(array);


    //------//
    CDS_dynamicArray_test_print(array);


    test_int_add = 35;
    printf("==== addIndex 35 ==== \n");
    CDS_dynamicArray_addIndex(array,0,&test_int_add);

    //------//
    CDS_dynamicArray_test_print(array);

    printf("is array empty %i \n",CDS_dynamicArray_isEmpty(array));

    //-----//
    printf("is 35 inside of array %i \n",CDS_dynamicArray_searchElement(array,&test_int_add,standart_int_compare));

    int test_int_search = 777;
    printf("is 777 inside of array %i \n",CDS_dynamicArray_searchElement(array,&test_int_search,standart_int_compare));

    printf("get element index = 2 %i \n",*((int*)CDS_dynamicArray_getElement_byIndex(array,2)));

    printf("last element is %i \n",*((int*)CDS_dynamicArray_getLastElement(array)));
    //-----//
    CDS_dynamicArray_test_print(array);

    printf("TEST :: func changeData :: change index 0 data with 99 \n");
    int test_int_changeData = 99;
    CDS_dynamicArray_changeData(array,0,&test_int_changeData);

    //-----//
    CDS_dynamicArray_test_print(array);

    printf("TEST:: findElement func parameter test_int_changeData %i: %p \n",test_int_changeData,CDS_dynamicArray_findElement(array,&test_int_changeData,standart_int_compare));

    printf("sorting..\n");
    CDS_dynamicArray_sort(array,standart_int_sort_compare);


    //-----//
    CDS_dynamicArray_test_print(array);
*/
    printf("%p \n", array);
    printf("%p \n", array->head);
    printf("%p \n", ((void**)(array->head) )[0]);
    CDS_dynamicArray_destroy(array);
    printf("%p \n", array);
    printf("%p \n", array->head);
    printf("%p \n", ((void**)(array->head) )[0]);
    printf("%p \n", a);

}
