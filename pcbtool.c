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
#include <stdnoreturn.h>

int deprecated(){

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

  
  

}



unsigned debug_level = DBG_LEVL; // Debug depth extend as number grow 
#ifdef DEBUG
  #define COL_CLR "\033[0m"

        #define DBG(level , fmt , ...) \
        if(debug_level >= level){ \
        if(level == 1) \
            #define COLOR "\033[0;32m" \  // Green
        if(level == 2) \
            #define COLOR "\033[0;33m"  \
        if(level == 3)\
            #define COLOR "\033[0;31m"  \
        \
        fprintf(stderr,"At file %s line %d : \t",__FILE__,__LINE__) ,\
                            fprintf(stderr ,COLOR fmt"\n" COL_CLR , ##__VA_ARGS__ );} // ## for the error depression purpose.
#else
    #define DBG(level , fmt , ...)
#endif

#define PRINTF(num) \
        if(num<0.001) \
          printf("%.6f\t\t",num); \
        else if(num<0.01) \
          printf("%.4f\t",num); \
        else \
          printf("%.2f\t",num);

typedef struct {
  float x;
  float y;
}Point;

void mil_to_milli(int sz , char** args);
void milli_to_mil(int sz , char** args); // sz : numer of the desired argument int argument list , args : actually pointer to the argument array
void soldermsk_gen(char* pt);

noreturn void error_exit();
noreturn void syntax_error_exit();
noreturn void input_syntax_error_exit();

int main(int argc , char** argv)
{

  if(argc < 2) error_exit();
  
  double* resul = NULL;

  char* opt = argv[1];

  if(*opt++ == '-')
    if(*opt == 'm'){
      DBG(2,"Entering function milli_to_mil.")
      milli_to_mil(argc-2,argv+2);  // we perform add/substract for the reason the function only hanles desired (actual numer list) argument
    }
    else if(*opt == 'M'){
      DBG(2,"Entering function mil_to_milli.");
       mil_to_milli(argc-2,argv+2);
    }
    else if(*opt == 'S'){
      DBG(2,"Entering function soldermsk_gen.");
      soldermsk_gen(argv[2]);
    } else error_exit();

  puts("");  

  DBG(1 , "\033[0;31m""Program normal exit.");
  exit(EXIT_SUCCESS);

}

// input origin point 
// input displacements 
// get  back tot origin point 

// calculate all points 
// extends 0.1 mm to all points
// output soldermask shape path ( in allegro command line syntax )

void  mil_to_milli(int sz , char** args)
{
  double* resul = (double*)malloc(sizeof(double)*sz);

  for(int i = 0;i<sz;++i)
  {
    resul[i] = ((atof(args[i]))*25.4 / 1000); PRINTF(resul[i]);
    
  }


}
void milli_to_mil(int sz , char** args) // sz : numer of the desired argument int argument list , args : actually pointer to the argument array
{
  double* resul = (double*)malloc(sizeof(double)*sz);

  for(int i = 0;i<sz;++i)
  {
    resul[i] = ((atof(args[i]))/25.4 * 1000) ; PRINTF(resul[i]);

  }

}

void soldermsk_gen(char* pt)
{
      Point pt_start;
      Point pt_itmd; // Intermediate processing point
      Point pt_array[256];

      //extract start point from commandline argument 
      if(*pt == '(')
        while(isspace(*(++pt)));
        while(isdigit(*(++pt)))
          pt_start.x = pt_start.x * 10 + (*pt) - '0';
        if(*pt == ',')
        while(isspace(*(++pt)));
        while(isdigit(*(++pt)))
          pt_start.y = pt_start.y * 10 + (*pt) - '0';
        if(*pt == ')');
      else
        syntax_error_exit();

    pt_itmd.x = pt_start.x , pt_itmd.y = pt_start.y;


    puts("Please enter a set of displacement of your pattern :");
    char c; unsigned i = 0 ,i_x =0 , i_y = 0; // Indexes for generating new point 
    while((c=fgetc(stdin))!='\n')
    {
      ungetc(c,stdin);
      if((c=fgetc(stdin)) == 'i')
      {
        if((c=fgetc(stdin)) == 'x')
        {
          while(isspace(c=fgetc(stdin)));
          ungetc(c,stdin);

          ++i_x;
          scanf("%f", &pt_itmd.x);

        }
        else if((c=fgetc(stdin)) == 'y')
        {
          while(isspace(c=fgetc(stdin)));
          ungetc(c,stdin);

          ++i_y;
          scanf("%f", &pt_itmd.y);

        }else ungetc(c,stdin);
        if(i_x == i_y)
        {
        pt_array[i].x = pt_itmd.x;
        pt_array[i].y = pt_itmd.y;
        pt_itmd.x = pt_itmd.y = 0;
        ++i;
        }else;
      }else input_syntax_error_exit();

          
    }

}

noreturn void error_exit()
{
 puts("Usage : pcbtool -<m,M,S> <number1/point> <number2> <number3> ...");
 puts("\tOptions :");
 puts("\t\t -m : millimeter to mil.");
 puts("\t\t -M : mil to millimeter.");
 puts("\t\t -S : create a solder mask pattern for irregular patterns");
 exit(EXIT_FAILURE);
}
noreturn void syntax_error_exit()
{
 puts("Point syntax error.");
 puts("Usage : pcbtool -S (<x>,<y>)");
 exit(EXIT_FAILURE);
}
noreturn void input_syntax_error_exit()
{
 puts("Input syntax error.");
 puts("Usage : ix <displacement> / iy <displacement>");
 exit(EXIT_FAILURE);
}