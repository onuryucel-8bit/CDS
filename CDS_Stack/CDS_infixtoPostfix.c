#include "CDS_infixtoPostfix.h"

///FIX STACK 09.06.23!

int get_precedence(char a){
    switch(a){
        case'+':
        case'-':
            return 1;
        case'*':
        case'/':
            return 2;

    }

    return -1;
}

///if a >= b return 1
///else return 0
int compare_precedence(char a,char b){
    if(get_precedence(a) >= get_precedence(b)){
        return 1;
    }
    return 0;
}


/**
 * Checks if a character is an operand.
 * An operand is any character that is not '+', '-', '*', '/', '(', or ')'.
 *
 * @param c The character to be checked.
 * @return Returns 1 if the character is an operand, 0 otherwise.
 */
int isOperand(char c){
    switch(c){
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
        return 0;
    }
    return 1;
}

int isOperator(char c){

    switch(c){
    case '+':
    case '-':
    case '*':
    case '/':

        return 1;
    }
    return 0;

}

void infix_to_postfix(char* infix){

    unsigned int size = strlen(infix);
    printf("size = %i\n",size);
    ///TODO make dynamic array
    char postfix[1204];

    int postIndex = 0;

    //init stack
    cdst_stack_Holder* stack = CDS_StackLL_init();

    //read infix string left to right
    for(int i = 0; i < size;i++){

      //  printf("%s\n",postfix);
        //if next char is operand put inside the postfix list
        if(isOperand(infix[i])){

            //put first char in postfix
            postfix[postIndex] = infix[i];
            postIndex++;

            //read next number
            char c;
            while(1){

                c = infix[i + 1];
                if(isOperand(c) && i + 1 < size){
                    i++;
                }else{
                    break;
                }

                postfix[postIndex] = infix[i];
                postIndex++;

            }

            //put spaces between numbers
            postfix[postIndex] = ' ';
            postIndex++;


        }//if end

        //if next char is operator
        else if(isOperator(infix[i]) ){
             //printf("isOperator() = %i\n",i);
             //if stack is empty put operator in stack
             if(CDS_StackLL_isEmpty(stack)){
                 CDS_StackLL_push(stack,&infix[i]);

             }

             else if(compare_precedence( *(char*)(stack->top->data) ,infix[i])){

                 ///TODO use CDS_StackLL_getTop(); or make top* CDS_StackLl_pop();
                 postfix[postIndex] = *(char*)(stack->top->data);
                 postIndex++;
                 CDS_StackLL_pop(stack);
                 CDS_StackLL_push(stack,&infix[i]);

             }
             //precedence Top < infix[i]
             else{
                 CDS_StackLL_push(stack,&infix[i]);
             }


        }

        else{
            //printf("isParanths() = %i\n",i);

            //push paranths
            if(infix[i] == ')'){

                while(*(char*)(stack->top->data) != '('){
                    postfix[postIndex] = *(char*)(stack->top->data);
                    postIndex++;
                    CDS_StackLL_pop(stack);
                }

                CDS_StackLL_pop(stack);

            //if infix[i] == '('
            }else{
                CDS_StackLL_push(stack,&infix[i]);
            }
        }



    }//FOR END---

    //pop and put inside the postfix
    while(CDS_StackLL_isEmpty(stack) != 1){

        postfix[postIndex] = *(char*)(stack->top->data);
        postIndex++;

        CDS_StackLL_pop(stack);

    }

    postfix[postIndex] = '\0';

    printf("-------------\n");
    printf("%s",postfix);

    //frees stack
    CDS_StackLL_destroy(stack);
}


