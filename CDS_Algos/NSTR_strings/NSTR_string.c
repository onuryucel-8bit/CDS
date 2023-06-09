#include "NSTR_string.h"

void NSTR_free_str(char* str){
    free(str);
}

double NSTR_toNumberDecimal_double(char* str){

    double number = 0;

    ///TODO code here !

    return number;
}


char* NSTR_dup(const char* str){
    unsigned int len = strlen(str) + 1;
    char* new_str = malloc(len);
    if (new_str != NULL) {
        memcpy(new_str, str, len);
    }
    return new_str;
}

char* NSTR_subStr(char* str,unsigned int start,unsigned int end){

    char* substr = malloc(sizeof(char) * 1204);

    unsigned int substrIndex = 0;
    for(int i = start; i < end + start; i++){
        substr[substrIndex] = str[i];
        substrIndex++;
    }
    substr[substrIndex] = '\0';
    return substr;
}
