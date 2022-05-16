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


// Section 15 Challenge #1 to 4
/*
    #1 jjjj
        Manually compile and run your code
            Compile many times with multiple options
                try changing the object name  :
                add debugging information :
                add warnings : 
                display warning as errors :
    #2
        Fix the bugs in provided code (udemy )
            using fprintf(stderr,...) , or macro instead 
            set debug level

            using conditional compilation ( -D DEBUG)
    #3
        compile with -g
        use debugger to figure out the problems in provided code

    #4
        debugging with core dumps 
            1 . set core dump size limit : ulimit -c ulimited
        debugging with core dump files in gdb ( run backtrace to analy the core file)

        
*/

int sum(int x, int y, int z) {
  char c = 2;
  int *a = NULL;

  fprintf(stderr, "x=%d\n", x);
  fprintf(stderr, "y=%d\n", y);
  fprintf(stderr, "z=%d\n", z);
  fprintf(stderr, "a=%ld\n", (long)a);
  
  *a = 5;

  fprintf(stderr, "*a=%d\n", *a);

  return (c + x + y + z + *a) / 3;
}

//int sec15_cha1()
int main(int argc, char *argv[]) {
  int i, j, k;
  int result;

  fprintf(stderr, "Number of parameters = %d\n", argc);

  if (argc == 1) {
     printf("Please specify three numbers as parameters.\n");
     exit(1);
  }

  i = atoi(argv[1]);

  fprintf(stderr, "i=%d\n", i);

  j = atoi(argv[2]);

  fprintf(stderr, "j=%d\n", j);

  k = atoi(argv[3]);

  fprintf(stderr, "k=%d\n", k);

  result = sum(i,j,12) + sum(j,k,19) + sum(i,k,13);

  printf("%d\n", result);

  return 0;
}


/* main without debuggin 


#include <stdlib.h>
#include <stdio.h>

int sum(int x, int y, int z) {
  char c = 2;
  int *a;

  *a = 5;

  return (c + x + y + z + *a) / 3;
}

int main(int argc, char *argv[]) {
  int i, j, k;
  int result;

  if (argc == 1) {
     printf("Please specify three numbers as parameters.\n");
     exit(1);
  }

  i = atoi(argv[1]);
  j = atoi(argv[2]);
  k = atoi(argv[3]);

  result = sum(i,j,12) + sum(j,k,19) + sum(i,k,13);

  printf("%d\n", result);

  return 0;
}
x
465554654455        


*/