

char emoji_favourite[] = "\U0001F499";

unsigned int emoji_count = 0;

char* emoji_random_alloc(){

return (char*)malloc(5*sizeof(char));

}

char* emoji_invertChar(char* orig){
     
     return 

}

char* emoji_invertAll(char* orig){

}



int emojis(){

// Three ways to representing emojis in your code.

char str[] = "\xF0\x9F\x8E\x89";

char* str1;
    str1 = malloc(5);
    str1[0] = 0xF0;
    str1[1] = 0x9F;
    str1[2] = 0x92;
    str1[3] = 0x99;
    str1[4] = 0x00;

char* str3 = "\U0001f389";


printf("%s , %s , %s\n" , str, str1, str3);
printf("strlen(s) : %ld , %ld , %ld",strlen(str), strlen(str1), strlen(str3));

return 0;

}
