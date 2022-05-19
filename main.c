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

// Section 17 Challenge #1

/*
    The goal of this challenge is to create a static library and then write a program that uses that library
     
    Create a C source file named "StringFunctions.c"

    StringFunctions.c should contain implementation of various string manipulation functions
      Find the frequency of characters in a string
      Remove all the characters in a String except Alphabets
      Calculate the length of string without using strlen
      Concatenate Two strings without using strcat
      Copy a string manually without using strcpy
      Find the substring of a given string

    Steps : 

      Create a header file that contains function prototypes of each string manipulation function in "StringFunctions.h"

      Create your "StringFunctions.c" source file that implements all of the funtions in the header file .
      
      create a static library (.a) containing your string manipulation functions 

      Create a program that acts as a driver for your string functions
        Test all your functions in this file.
        Statically link this program to your static library 

      Manually compile and run ( familiar with thoese commands )

      review the demostration and solution provided for further understanding 


*/

// Section 17 Challenge #2
/*  
    The goal of this challenge is to createa a shared object ( dll or dynamic library ) and then write a program that uses this library


    All steps are same as in Challenge#1 but except step 3. 
    Create a shared object library(.so) containing your string manipulation functions 
*/
// Section 17 Challenge #2
/*

    Dynamically load the shared objects library previously created.

    Create function pointers for all 6 string functions from the shared object library.

    Set the function pointers to the right symbol/function using the dlsym function
      use dlerror to check fro errors 

    Invoke all of the functions declared.


*/

int main()
{


}
