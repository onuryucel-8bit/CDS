#ifndef CDS_INFIX_TO_POSTFIX_H
#define CDS_INFIX_TO_POSTFIX_H


int get_precedence(char a);

int compare_precedence(char a,char b);

int isOperand(char c);

int isOperator(char c);

void infix_to_postfix(char* infix);

#endif //CDS_INFIX_TO_POSTFIX_H
