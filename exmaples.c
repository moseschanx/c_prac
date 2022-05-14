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

typedef struct {
    long sum;
    long mean;
}result ;

result calculate_sum(char, int, ...);

int test_va()
//int main(){

    result res = calculate_sum('a',5,1,2,3,4,5);
    printf("Calculated sum is %ld \n",(calculate_sum('a',5,1,2,3,4,5)).sum); 
    return 0;


}


result calculate_sum( char trivial, int count , ...){
    va_list args , args_cpy;
    va_copy(args_cpy,args);   
    va_start(args,count);

    // do your things here.
    long sum = 0;
    for(int i =0;i<count;++i)
        sum+=va_arg(args,int);

    va_end(args);

    long sub_sum = 0;
    long mean = 0;
    for(int i =0;i<count;++i)
        sub_sum += va_arg(args_cpy,int) , mean = sum/count;
 
    result my_res; 
    
    my_res.sum = sum;
    my_res.mean = mean;


    return my_res;

}

