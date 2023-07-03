#ifndef NSTR_STRING_H
#define NSTR_STRING_H

#include <string.h>
#include <stdlib.h>

//TODO 03.07.23 void NSTR_reverseStr(char* str);
//TODO 03.07.23 double NSTR_toNumberDecimal_double(char* str)

void NSTR_free_str(char* str);

char* NSTR_subStr(char* str,unsigned int start,unsigned int end);

char* NSTR_dup(const char* str);

void NSTR_reverseStr(char* str);

//theres atoi function in stdlib but its return int
double NSTR_toNumberDecimal_double(char* str);

#endif // NSTR_STRING_H
