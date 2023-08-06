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

    int a[]={16,20,34,48};
    for(int i = 0; i < sizeof(a) / sizeof(int); i++){
        CDS_dynamicArray_addLast(array,&a[i]);
    }

    //------//
    CDS_dynamicArray_test_print(array);

    int test_int_add = 10;
    printf("==== addLast 10 ==== \n");
    CDS_dynamicArray_addLast(array,&test_int_add);

    //------//
    CDS_dynamicArray_test_print(array);

    CDS_dynamicArray_sort(array,standart_int_compare);

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

    printf("TEST :: func changeData \n");
    int test_int_changeData = 99;
    CDS_dynamicArray_changeData(array,0,&test_int_changeData);
    //-----//
    CDS_dynamicArray_test_print(array);

    printf("sorting..\n");
    CDS_dynamicArray_sort(array,standart_int_sort_compare);


    //-----//
    CDS_dynamicArray_test_print(array);

    CDS_dynamicArray_destroy(array);
}
