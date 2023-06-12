#ifndef CDS_INFIX_TO_POSTFIX_H
#define CDS_INFIX_TO_POSTFIX_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"../NSTR_strings/NSTR_string.h"
#include"CDS_StackLL.h"

int get_precedence(char a);

int compare_precedence(char a,char b);

int isOperand(char c);

int isOperator(char c);

void infix_to_postfix(char* infix);

#endif //CDS_INFIX_TO_POSTFIX_H
