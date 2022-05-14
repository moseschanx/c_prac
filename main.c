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

// Section 14 Challenge #1
/*

    Write a program to print the value of the following 
    predefined symbolic constant 
    __LINE__
    __FILE__
    __DATE__
    __TIME__
    __STDC__

#2
    Write a program that defines a macro that accepts two parameters 
    and return the sum of the given numbers
    #define MACRO_NAME(params) MACRO_BODY
    Your program should have the user enter the two numbers
#3
    Create SQUARE and CUBE macro
    Your program should have the user enter any number
    Your program should then dispaly the square and cube of the number
    as output by invoking the above macros

    Example output:
    Enter any number to find square and cube : 10
    SQUARE(10) =  100
    CUBE(10) = 1000

#4
    Write a C program to check whether a character is uppercase or lowercase
    using macros

    You should create two macros that accept a single argument (character)
    IS_UPPER
    IS_LOWER
    both of the macros should return a boolean
        true(1) or false(0) based on whether they are upper or lower case

    Your macro will need to include a conditional and can use logical operators

    Your program should have the user enter any character (getchar())

    Your program should then display whether the character is upper or lower
    case as ouput by invoking the above macros

    Example output:
    Enter any character : C
    'C' is uppercase

    Enter nay character :8
    Entered character is not in the alphabet

    ## additional enhancements
    Feel free to add the below macros to perform additional checks on
    characters

    logic to check alphabtic digits alplhanumeric , vowels, consonants,
    special characters , white space etc.
        some of the above macros can use the other macros
            an IS_ALPHANUMERIC macro could use an IS_ALPHABET and IS_DIGIT
            marcros

*/

//int sec14_cha1to4()
int main()
{
    /*Challenge #1
    printf("__LINE__ is : %d\n",__LINE__);
    printf("__FILE__ is : %s\n",__FILE__);
    printf("__DATE__ is : %s\n",__DATE__); 
    printf("__TIME__ is : %s\n",__TIME__);
    printf("__STDC__ is : %d\n",__STDC__);
    */

    /*Challenge #2
#define SUM_OF_TWO(param1,param2) ((param1)+(param2))

    	int num1,num2;
	printf("Please input two numer to get sum (by using macro) :");
	scanf("%d%d",&num1,&num2);

	printf("Your sum is : %d",SUM_OF_TWO(num1,num2));

    */
    
    /*Challenge #3
#define CUBE(param) ((param)*(param)*(param))
#define SQUARE(param) ((param)*(param))
   	int num3; 
	printf("Enter any number to find square and cube :");
	scanf("%d",&num3);

	printf("Square of %d is : %d \n",num3,SQUARE(num3));
	printf("Cube of %d is : %d \n",num3,CUBE(num3));


    */

    //Challenge #4
#define IS_UPPER(param) (((param)<=90 && (param)>=65) ? 1 : 0)
#define IS_LOWER(param) (((param)<=122 && (param)>=97) ? 1 : 0)

    //
    

    return 0;

}





