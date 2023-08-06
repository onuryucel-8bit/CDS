#include <stdio.h>
#include"CDS_DynamicArray.h"

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

    printf("==== removeLast 10 ==== \n");
    CDS_dynamicArray_removeLast(array);


    //------//
    CDS_dynamicArray_test_print(array);


    test_int_add = 35;
    printf("==== addIndex 35 ==== \n");
    CDS_dynamicArray_addIndex(array,0,&test_int_add);

    //------//
    CDS_dynamicArray_test_print(array);

    printf("is array empty %i",CDS_dynamicArray_isEmpty(array));

    //-----//


    CDS_dynamicArray_destroy(array);
}
