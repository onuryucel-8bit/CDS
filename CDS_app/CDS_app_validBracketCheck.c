#include"CDS_app_validBracketCheck.h"

///FIX STACK 09.06.23!

int isMatchingPair(char c,cdst_stack_Holder* stack){
    if((c == ')' && CDS_StackLL_getType_char_Top(stack) == '(')  ||
       (c == ']' && CDS_StackLL_getType_char_Top(stack) == '[')  ||
       (c == '}' && CDS_StackLL_getType_char_Top(stack) == '{')   ){
        return 1;
    }
    return 0;
}

int bracket_Problem(char* str){

   cdst_stack_Holder* stack = CDS_stack_lil_init(CDS_STACK_ALLOCATE);

   unsigned int size = strlen(str);

   for(int i = 0;i<size;i++){

        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            CDS_stack_lil_push(stack,&str[i]);
        }

        if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if(CDS_stack_lil_isEmpty(stack)){
                return 0;
            }
            else if(isMatchingPair(str[i],stack)){
                CDS_stack_lil_pop(stack);
            }else{
                return 0;
            }
        }
   }
/*
   while(!CDS_stack_lil_isEmpty(stack)){
        CDS_stack_lil_pop(stack);
   }
*/

   CDS_stack_lil_destroy(stack);
   return 1;
}

