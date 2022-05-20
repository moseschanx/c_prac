
#include <stdbool.h>

#include "string_functions.h"
int number_of_characters_in_string(char* str , char srchCha)
{
    char c ;
    unsigned cnt = 0;
    while((c = (*str++)) != '\0')
        if(c == srchCha) ++cnt;
}


bool remove_non_alpha_characters(char* src)
{

    char* c;
    while((c = (*src++))!='\0')
    {
        if(!(c <= 'z' && c >= 'a' ||c <= 'Z' && c >= 'A'))
            (*(src-1)) = '\0';

    }
    return 0;
    
}

int length_of_string(char* src)
{
    unsigned len=0;
    while(*src++ != '\0')
        ++len;

    return len;
}

bool str_cpy(char* src, char* dest)
{
    while(*src++ != '\0')
        *dest++ = *src;
}

bool sub_str(char* src, int i_start, int n, char* dest)
{

    for(;i_start!=0;--i_start,++src);
    for(;n != 0 && *src != '\0';--n, *dest++ = *src++);

    return 0;

}