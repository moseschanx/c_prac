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

// Section 16 Challenge #1 to 2
/* 

#1
    Write a program that creates , assigns , and accesses some double pointers.
      1. Create a normal integer variable ( non pointer ) and assign a random value 
      2. Create a single integer pointer variable.
      3. Create a double integer pointer variable.
      4. Assign the address of the normal integer variable ( step 1 ) to the 
         single pointer (step 2)
      5. assign the address of the single pointer (step 2 ) to the double pointer
      variable (step 3)

      Dis play the following output using all possible syntax
        All possible ways to find value of the normal integer variable ( step 1)
        All possible ways to find address of the normal integer variable ( step 1)
        All possible ways to find the value of the single pointer variable ( step 2)
        All possible ways to find the address of the single pointer variable ( step 2)
        All possible ways to print the double printer value and address ( step 3)

      Example Output : 
        Value of num is : 123
        Value of num using snglePointer is : 123
        Value of num using doublePointer is : 123

        Address of num is  : 0x
        Address of num using single pointer is : 0x
        Address of num using double pointer is : 0x 

        Value of Pointer singlePointer is : 0x
        Value of pointer singlePointer using doublePointer is : 0x

        Address of Pointer singlePointer is : 0x
        Address of Pointer singlePointer using doublePointer is : 0x

        Value of Pointer doublePointer is : 0x
        Address of Pointer doublePointer is : 0x
#2
    Write a program that includes a function that modifies a pointers value 
      Not the value that the pointer in pointing to
      The actual value of the pointer ( the address that the pointer is pointing to)

    Notes : Essentially this program will be simulating "pass by reference " in the Cpp Language
      You want to change the value of the pointer passed to a function as the function argument

    1. Create a function named allocateMemory that takes a single integer pointer as a function parameter 
        void allocateMemeory(int *ptr);
        this function should allocate memory for this pointer 

    2. Now create a main function that does the following : 
      Creates an integer pointer and initializes it to NULL
      Invokes that allocateMemroy function , passing in the integer pointer just created
      assign a value to the integer pointer that it is pointing to ( de-reference )
      print the value of what the pointer is pointing to ( de-reference )
      free the pointer 
    
    3. Now modify your prorgam to use a double pointer
      modify the function named allocateMemory to take a double pointer of type int as a 
      function parameter 
        void allocateMemory(int **ptr);
        this function should allocate memory for this pointer ( use the correct syntax)

    4. Now modify your main function that does the following :
      Creates an interger pointer and initializes it to NULL
      Invokes that allocateMemory function , passing in the address of the interger pointer 
      just created ( double pointer )
      Assign a value to the integer pointer that it is pointing to ( de-reference )
      print the value of what the pointer is pointing to ( de-reference )
      free the pointer.

      Understand what the output of the program is , and why.

# function pointer Challenge 

    int array1[]
    int array2[]

    int add(int a , int b )  
        sub
        mult
        div 

    ~Array of pointer to functions 
    ~Perform the opetation 
    ~Display the results

    1. Create an array of function pointers that pointer to each arithmetic function
    (add sub mult div)

    2. add a fourth parameter to the performOp function so that it takes a function pointer
    with the singnature of the arithmetic functions.

    3. Pass in the correct function pointer ( array index )
  
    4. Include the code for the function performOp
      Your code should invoke the function pointed to from the parameter passed in 
        Will perform the operation on elements of the two arrays passed in and 
        store the result in a third array 
        Function should return the new array containing the results

    5. Include the code for the function display
      Your code should display as output all the elements of the given array in a readable format

      test your program to the performOp function 

    4. include the code for the function performOp
      Your code should invoke the function pointed to from the parameter passed in 
        Will perform the operation on elements of the two arrays passed in and store 
        the result in a third array.
        Function should return the new array containing the result .

    5. Include the code for the function dispaly
        Your code should display as output all the element of the given array in a readable format

        test your code with different user choices



  Example Output : 
    Which operation do you want to perform?
    1. Add
    2. Substract
    3. Multiply 
    4. Divide
    5. None
    Enter choice : 2

    The results are ...


*/     
//int sec16_cha1to2()
int main()
{

}
