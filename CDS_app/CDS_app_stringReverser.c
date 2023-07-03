#include"CDS_app_stringReverser.h"

void CDS_app_stringReverser_run(cdst_stack_Holder* stack,char* str,unsigned int size){

    if(stack == NULL)return;

    printf("str %s \n",str);

    //substr
    //put in stack
    for(int i = 0; i < size; i++){
        char* c = malloc(sizeof(char));
        *c = str[i];
        CDS_StackLL_push(stack,c);
    }

    //pop
    char* reverse_str = malloc(sizeof(1204));
    for(int i = 0; i < size; i++){

        char c = *(char*)(stack->top->data);
        reverse_str[i] = c;
        //printf("%c \n", c);
        CDS_StackLL_pop(stack);

    }
    reverse_str[size] = '\0';

    //printf
    printf("reverse str %s \n",reverse_str);
    //free
    free(reverse_str);
}
