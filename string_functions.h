#ifndef STRING_FUNC_H
#define STRING_FUNC_H

#ifdef __cplusplus
      extern "C"{
#endif

      /*
      str - string to search
      srchCha - character to look for
      return type - int : count for the number of times that character was found
      */
     int number_of_characters_in_string(char* str , char srchCha);

     /*
     src - source string
     return type - int : 0 on success
     */
     bool remove_non_alpha_characters(char* src);

     /*
     src - source string
     return type - int : length of string
     */
     int length_of_string(char* src);

     /*
     src - string to copy from
     dest - second string to copy to 
     return type - bool : 0 on succes
     */
     bool str_cpy(char* src, char* dest);

     /*
     src - source string
     i_start - starting index from where you want to get substring
     n - number of characters to be copied in substring
     dest - target string in which you want to store target string 
     return type - bool : 0 on success 
     */
     bool sub_str(char* src, int i_start, int n, char* dest);

#ifdef __cplusplus
      }
#endif
     
#endif