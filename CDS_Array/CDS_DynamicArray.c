#include "CDS_DynamicArray.h"

//----------STATIC--------------------//

/**
*   size can only be 1 or -1
*   1 resize up
*  -1 resize down
*
*   resize_amount is size_t type
*/
static void sta_dynamicArray_resize(cdst_array* array,char size){

    #ifdef DEBUG_SHIFT_RIGHT_CAPS
        printf("DEBUG :: array cap %u \n", array->capacity);
    #endif

    //resize_amount error check
    void* new_head = NULL;

    if(array->resize_amount != 0){
        new_head = realloc(array->head,array->capacity + (size * array->resize_amount));

        //realloc error check
        if(new_head == NULL)return;

        array->capacity += array->resize_amount;

    }else{
        new_head = realloc(array->head,array->capacity + (size * DEFAULT_RESIZE_AMOUNT));

        //realloc error check
        if(new_head == NULL)return;

        array->capacity += DEFAULT_RESIZE_AMOUNT;
    }


    #ifdef DEBUG_SHIFT_RIGHT_CAPE
        printf("DEBUG :: array cap %u \n", array->capacity);
    #endif

    //assigning new head
    array->head = new_head;

}

static void sta_dynamic_array_shiftRight(cdst_array* array,size_t index){

    //check if array capacity not enough for operation
    if(array->index + 1 >= array->capacity){
        //resize
        sta_dynamicArray_resize(array,1);
    }

    //shift

    //these variables for unsigned int problems
    /*
    *  let say i = 0
    *  i-=2;
    *  then i will be 4564... (big number)
    *
    */
    int s = index;
    int i = array->index - 1;

    for(; i >= s; i--){
        ((void**)(array->head))[i + 1] = ((void**)(array->head))[i];
    }
}

static void sta_dynamic_array_shiftLeft(cdst_array* array,size_t index){

    #ifdef DEBUG
        printf("DEBUG :: array_shiftleft working...\n");
    #endif // DEBUG
    //resize array
    if(array->capacity - 1 - array->index >= DEFAULT_RESIZE_AMOUNT && array->resize_amount == 0){

    }else if(array->capacity - 1 - array->index >= array->resize_amount && array->resize_amount != 0){
        //sta_dynamicArray_resize(array);
    }

    //shift
    for(int i = index; i <= array->index; i++){
        ((void**)(array->head))[i] = ((void**)(array->head))[i + 1];
    }
}

cdst_array* CDS_dynamicArray_init(size_t capacity){

    cdst_array* newArray = malloc(sizeof(cdst_array));

    //null ptr check
    if(newArray == NULL){
        return NULL;
    }

    newArray->head = malloc(sizeof(void*) * capacity);

    //null ptr check
    if(newArray->head == NULL){
        return NULL;
    }

    for(int i = 0; i < capacity; i++){
          //convert void pointer to .pointer to pointer
        ( (void**)(newArray->head) )[i] = NULL;
    }

    newArray->capacity = capacity;
    newArray->index = 0;
    newArray->resize_amount = DEFAULT_RESIZE_AMOUNT;

    return newArray;
}

//----------------ADD----------------//

/**
*  put element to desired index and shift elements
*  if index is out of bounds it will add element to end of array
*/
void CDS_dynamicArray_addIndex(cdst_array* array,size_t index,void* data){

    //check error
    if(array == NULL || array->head == NULL)return;

    //if index is equal of end of array
    if(index >= array->index){
        CDS_dynamicArray_addLast(array,data);
        return;
    }

    //shift + resize
    sta_dynamic_array_shiftRight(array,index);

    //add data
    ((void**)(array->head))[index] = data;
    array->index++;

}

void CDS_dynamicArray_addLast(cdst_array* array,void* data){

    //check error
    if(array == NULL || array->head == NULL)return;

    //add data
    ((void**)(array->head))[array->index] = data;
    array->index ++;

    //resize
    /**
    *  about resize
    *
    *  let say
    *  array->index is pointing out of array right now
    *  resize function will be realloc array->capacity + DEFAULT_RESIZE_AMOUNT or(not bitwise OR) array->resize_amount
    *  amount of byte on heap
    *
    *  array->capac => 5
    *
    *  index  0   1   2   3   4   5
    *        ___________________________
    *  array |a | b | c | d | e |
    *        ---------------------------
    *               array->index--^
    *
    *  if DEFAULT_RESIZE_AMOUNT = 5 used
    *
    *  index  0   1   2   3   4   5   6  ....9
    *        ___________________________
    *  array |a | b | c | d | e |   |   | .....
    *        ---------------------------
    *               array->index--^
    *
    *
    */
    if(array->index >= array->capacity){
        //for meaning of parameter (char) size look for resize func comments
        sta_dynamicArray_resize(array,1);
    }
}

//--------------REMOVE---------------//

void CDS_dynamicArray_removeIndex(cdst_array* array,size_t index){

    //check error
    if(index >= array->index)return;

    //delete
    ((void**)array->head)[array->index] = NULL;

    //shift
    sta_dynamic_array_shiftLeft(array,index);

    array->index--;
}

/**
*  remove last element
*/
void CDS_dynamicArray_removeLast(cdst_array* array){

    //error check
    if(array == NULL || array->head == NULL)return;

    //TODO free memory

    //delete
    free(( (void**)(array->head) )[array->index - 1]);
    array->index --;

    //TODO rezise
    if(array->index == 0){

    }


}

//---------------UTILS---------------//

//--LAST ELEMENT--//
/**
*   it will return i index of address element
*   return array[i]
*/
void* CDS_dynamicArray_getElement_byIndex(cdst_array* array,unsigned int index){

    if(array == NULL || array->head == NULL)return NULL;

    return ((void**)(array->head))[index];
}

/**
*   it will return last address of element
*   return array[index-1]
*/
void* CDS_dynamicArray_getLastElement(cdst_array* array){

    if(array == NULL || array->head == NULL)return NULL;

    return ((void**)(array->head))[array->index - 1];
}

//--SEARCH-FIND--//
/**
*   if findData inside of array return 1;
*   else return 0;
*
*   DEFINE FUNCTION : COMPARE(void*,void*)
*   if(a==b)return 1
*   return 0
*/
int CDS_dynamicArray_searchElement(cdst_array* array,void* findData,int compare(void* element1,void* element2)){

    if(array == NULL || array->head == NULL || findData == NULL)return NULL;

    //searching in array
    for(int i = 0; i < array->index; i++){
        //compare
        if(compare( ( (void**)(array->head) )[i]  , findData)  ){
            return 1;
        }
    }

    return 0;
}

/**
*   DEFINE FUNC(void*, void*)
*       if a == b return 1
*       else return 0
*
*   if findData inside of array return pointer of findData
*   else return NULL
*/
void* CDS_dynamicArray_findElement(cdst_array* array,void* findData,int compare(void* element1,void* element2)){

    if(array == NULL || array->head == NULL || findData == NULL)return NULL;

    //search in array
    for(int i = 0; i < array->index; i++){
        //compare
        if(compare( ((void**)(array->head) )[i]  , findData)  ){
            return ((void**)(array->head) )[i];
        }
    }

    return NULL;
}

//------------------------------//

/**
* prints data int type
*/
void CDS_dynamicArray_test_print(cdst_array* array){
    for(int i = 0; i < array->index;i++){
        int* element = ((int**)(array->head))[i];
        printf("element %i ptr : %p \n",*element,(((int**)(array->head))[i]));

    }
    printf("*****\n");
}

/**
*  DEFINE COMPARE FUNC: (void*,void*)
*  if findData > array.data   return 1
*  else if findData <= array.data return 0
*
*  bubble_sort
*/
void  CDS_dynamicArray_sort(cdst_array* array,int compare(void* fdata,void* sdata)){

    if(array == NULL || array->head == NULL)return;

    void* temp = NULL;
    size_t size_arr = array->index;

    for(size_t i = 0;i < size_arr - 1; i++){

        for(size_t j = 0; j < size_arr - i - 1; j++){

            if(compare(((void**)(array->head) )[j] ,((void**)(array->head) )[j+1])){

                temp = ((void**)(array->head))[j];
                ((void**)(array->head) )[j] = ((void**)(array->head) )[j+1];
                ((void**)(array->head) )[j+1]= temp;

            }

        }//for j end

    }//for i end

}

void CDS_dynamicArray_changeData(cdst_array* array,size_t index,void* data){

    if(array == NULL || array->head == NULL)return;
    ((void**)(array->head))[index] = data;

}

/**
*  its checks array->head is empty
*
*/
int CDS_dynamicArray_isEmpty(cdst_array* array){

    if(array->head == NULL){
        return CDS_TRUE;
    }

    return CDS_FALSE;
}

void  CDS_dynamicArray_destroy(cdst_array* array){

    for(int i = 0; i < array->index; i++){
        free(((void**)(array->head) )[i]);
    }

    free(array->head);

    free(array);

    array = NULL;
}


