#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <complex.h>
#include <math.h>
#include <stdbool.h>
#include <setjmp.h>
#include <assert.h>
#include <ctype.h>


void sizeCheck(){

    printf("size_t is : %lu\n",sizeof(size_t));
    printf("short is : %lu\n",sizeof(short));
    printf("int is : %lu\n",sizeof(int));
    printf("long is : %lu\n",sizeof(long));
    printf("long long is : %lu\n",sizeof(long long));

}

void demo_scanf(char *fmt , FILE* stream){

    while(*fmt!='\0'){
        if(*fmt == '%')
        {
            int c;
            switch(*++fmt){
                case 'u':
                    while(isspace( c = fgetc(stream)));
                    unsigned sum = 0;
                    while(isdigit(c))
                    {
                        sum = sum*10 + c - '0';
                        c = fgetc(stream);
                    }
                    ungetc(c,stream);
                    printf("%%u scaned %u\n",sum);

                    break;
                case 'c':
                    c = fgetc(stream);
                    printf("%%c scaned %c \n",c);

                    break;
            }
            
        }else{
            ++fmt;
        }
    }

}


int use_demo_scanf(int argc , char** argv){
//int main(int argc , char** argv){
    

    FILE* fp = fopen("myname","w+");

    fputs("1669BC",fp);
    rewind(fp);
    demo_scanf("%u%c%c",fp);

    if(ferror(fp)){
        perror("Error");
    }else if(feof(fp)){
        puts("EOF reached. Program Exit().");
        fclose(fp);
        remove("myname");
        exit(EXIT_SUCCESS);
    }
}



struct {
    char *name;
    union{
        int i;
        float f;
        char c;
    }data;

}table [entries];

int main(){


    return 0;


}