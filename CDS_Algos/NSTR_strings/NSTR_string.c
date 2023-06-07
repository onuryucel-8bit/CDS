#include "NSTR_string.h"

void NSTR_free_str(char* str){
    free(str);
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
