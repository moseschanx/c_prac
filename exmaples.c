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
        remove("myname");//StringFunctions.c


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

// MACROS 

    #define CONCAT(a,b) a##b
    #define WARNING(...) fprintf(stderr,__VA_ARGS__)
    #define PUTS(param) (puts(#param))
    #define MAKE_FUNCTION(NAME) void print_##NAME(char* str){\
                                puts("In fucntion : print_"#NAME );\
                                printf("Your parameter is : %s ",str);\
                                }
    #define MAKE_FUNCTION_DECL(NAME) void print_##NAME()
    #define MAKE_FUNCTION_CALL(NAME,STR) print_##NAME(STR)

    MAKE_FUNCTION_DECL(MOSESCHAN);

    MAKE_FUNCTION(MOSESCHAN)


#define COMMAND(NAME) {#NAME,NAME##_command}


struct command{
    char* name;
    void (*function)(void);
};

struct command commands[]={
    {"quit",quit_command},
    {"exit",exit_command},
    {"draw",draw_command}
    COMMAND(help)
    
};

// Generic programming in C using macro.
#define DeclarSort(prefix , type) \
static int _DeclareSort_ ## prefix ## _Compare(const void *a, const void *b){\
    const type *aa; const type *bb; \
    aa = a; bb = b; \
    if(aa<bb) return -1;\
        else if(bb<aa) return 1;\
        else return 0;\
}\
void prefix##_sort(type *a , int n){\
qsort(a,sizeof(type),n,_DeclareSort_## prefix ##_Compare);\
}


DeclarSort(int , int)

int pcbtool_prototype(){

unsigned choice;

start:
    printf("Select function : \n \
            \t \t 1.millimeter to mil.\n \
            \t \t 2.Mil to millimeter. \n \
            \t \t \t");
    scanf("%d",&choice);
    if(choice == 1)
      goto mtoM;
    if(choice == 2)
      goto Mtom;
    else
      goto start;


  float mm , mil;

mtoM:
  printf("millimeter to mil : ");

  if(getchar() == 'b')
  {
    switch(getchar()){
      case '1' :
        puts("");
        goto mtoM;
      case '2' :
        puts("");
        goto Mtom;
    }
    goto start;
  }
  scanf("%f",&mm);

  mil = (mm / 25.4)*1000; 

  printf("%.2f\n",mil);
  goto mtoM;

Mtom:
  printf("Mil to millimeter: ");
  if(getchar() == 'b')
  {
    switch(getchar()){
      case '1' :
        puts("");
        goto mtoM;
      case '2' :
        puts("");
        goto Mtom;
    }
    goto start;
  }

  scanf("%f",&mil);

  mm = (mil * 25.4)/1000; 

  printf("%.4f\n",mm);
  goto Mtom;

  
  


  printf("Random number in [0,%d) : %d\n",RAND_MAX,random_number);

  time_t epoch = time(NULL);
  printf("%jd seconds since the epoch began \n",(__intmax_t)epoch);


  // struct tm* localtime ( const time_t *timer);
  // time_t time ( time_t *arg);
  // char* asctime(const struct tm* time_ptr);
  // struct tm* gmtime(const time_t *timer);
  // time_t mktime( struct tm* time );

  // void srand(unsigned seed);

  /* struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
  }
  */

  struct tm* tm = localtime(&(time_t){time(NULL)});
  printf("localtime is : %s\n",asctime(tm));

  tm = gmtime(&(time_t){time(NULL)});
  
  printf("gm time is : %s \n",asctime(tm));

  printf("DST is %s \n",tm->tm_isdst?"in effect" : " no in effect ");

  struct tm tm0 = {.tm_mday=26 , .tm_isdst = true , .tm_year = 101  , .tm_mon = 9-1};
  
  mktime(&tm0);

  printf("After mktime() %s\n",asctime(&tm0));


srand(time(NULL));

for(int i = 0;i<20; ++i){

  static float a  = 0;
  a = (rand()%2001 -1000) / 2.e3;
  printf("%.4f ", a);


}


int find_max(int nums[],int len)
{
  int i , max_num = nums[0];
  for(i=1;i<len;++i){
    if(max_num<nums[i])
      max_num = nums[i];
  }
  return max_num;
}