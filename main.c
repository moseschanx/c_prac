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
#include <dlfcn.h>
#include <time.h>


// Section 18 Challenge  
/*

  #1
    test your understanding of random numbers

    Write a C program taht generate 50 ramdom numbers between -0.5 and 0.5

    Out put the random numbers
      the first line of output should be the number of data 
      the next 50 lines should be the 50 random numbers

    You're required to use the srand function , passing in the time function 
      as a seed to using the rand() function.

  #2
    test your understanding of the quick sort algorithm ( qsort() ) from the stdlib.h file

    Write a program that will sort an array of doubles from lowest to highest using the qsort function 
    Create a function that takes a double array and a size parameter which generates some random double values

      void fillarray(double ar[],int n);

    Create a function that takes a double array and a size parameter which generates some random double values
      void showarray(const double ar[] , int n);

    Your main function should 
      Create an array 
      fill it with random numbers
      display it 
      sort it using qsort 
      display the sorted array

  #3
    test your understanding of getting the current time 

      Write a program to print the current time
      You should see the time and ctime functions
      You should handle errors using fprintf and the exit function with the correct failure code 

  #4

    test your understanding of using the tm structure 

    Write a program to compute the number of seconds passed since the beginning of the current month
      You should use the localtime , difftime , and mktime functions
      You should handlel errors using fprintf and the exit function with the correct failure codes
*/

// Section 19 Challenges
/*

  #1 Linked List 
    test your understanding of linked list 
    
  Write a program that performs operations on a linked list 

  You need to create a linked list that stores integers and uses pointers

  Your program should perform the following operations 
    Inseret node at first
    Insert node at first
    Insert node at position 
    Delete node from any position 
    Update node value 
    Search Element in the linked list 
    Display list
    Exit

  Your program should create a strructure that stores each nodes value and contains a next pointer

  Your program can utilize global variables for previous , head, tail , temp , new nodes, etc 
  or you can pass around data to function 
    
  #2 Implement Stack an queue

  

*/

// Section 20 Challenge.
/*

  #1
    test your understanding of signals 

    Specifically , your progam will :
      raise signals 
      catch singals 
      use the alarm function to raise a signal 

    Write a program that will test a user's multiplication skills 
      the progam will ask the user to work on an answer to simple multiplication progam
      keep track of how many answers are correct

    The program will keep running forever , unless
      the user presses Ctrl-C OR
      the user takes more than 5 seconds to answer the question 

    When the program ends, it will display the final score ( number of answer correct )


        Do some modification / addition to Challenge1_starter_code.c

          You will need to add code for the following
            The program needs to handle the user pressing Ctrl+C
              will need to handle this signal using the signal or sigaction functions
          
            The program needs to raise a signal if the user does not answer a question within 5 seconds
              use the alarm function and catch the SIGALRM singal.

  #1 ( Testing )
    To test the progam , you will need to run it a couple of times 

    the first time , you should answer a few questions and then hit CTRL+C
      ctrl-c sends the process an interrupt signal that makes the program display the final 
      score and then exit()

    the second time , wait for at least five seconds on one of the answer and see what happens
      the alarm signal ( SIGALRM ) should occur
        the program was waiting for the user to enter an answer , but because he took so long, the timer signal wa sent
        program should ouput "time's up " and then raise the SIGINT signal which causes the progam to display the final score

  
  #2
    test your understanding of forking a process 

    write a program to create one parent with three children processes ( four processes)
      must use the fork() function

    your program should contain output that identifies each parent and each child 
      will need to write if statements to check process id's returned from the fork() call,
      so that the output information is correct
        parent , first child , second child , third child 
        utilize the gepid() and getppid() functions to display each process id

      at some instance of time , it is not necessary that child process will execute first or parent 
      process will be first allotted CPU
        any process may get CPU assigned ,at some quantum time
        also . the process id may differ during different executions







*/

// Section 21 Challenge
/*
    #1
      test your understanding of threads 
        Creating and exiting threads , joining threads and passing arguments to thread fucntions

        Write a program in which multiple threads print a message 
          Create 10 seperate threads and have each thread call one function that takes an argument
            Pass a different number for each thread to your thread function.

          Might want to use an array to store each thread and to store each number.

        Create a global variable named counter and initialized it to 0 ( shared varibale amongst threads)

        Create one functoin that acepts on parameter (void*)
          function should get invoked for each thtead that you create.
          function should increment the global counter 
          function should then print out the message passed into it , its thread id ,and the global counter
          function should print out again the message passed into it , its thread id ,and the global counterr

        Lastly , the main thread should call join and exit on all of its child threads
          to make the original thread waitfor its child thread to complete

        run the program many times, did you notice anything strange about the global coutner
          counter values for the two print statements in the same thread

        


    #2 ( scheduling the race condition )
      test your understanding of threads and mutexes 
        you will make sure that data that is shared between threads in mutually exclusive when 
        updated and when read
            You should have consistent values in critical sections of code 
        the goal of this challenge iks to write thread-safe code 
          code that will produce the correct result regrardless of the order that threads are
          scheduled to run or if they're accessing shared resources

        you should have notices in challenge 1 that the global variable count value was a different value 
        when displayed on two consecutive statements in the same thread
          multiple threads would update the counter between the two print statements
        
        the global variable count should be the same value in each print statement for each thread
          when the data is modified by a thread , the same thread should be able to read that data 
          before it is modifed again by another thread

          data consistency of a shared resource , value is changing from statement to statement by another thread
        
        the counter variable is shared across multiple threads without any synchronization constructs to protect it 

        for the challenge , you'll need to edit the code from challenge 1 to create a mutex variable to ensure that 
        multiple threads do no access the varriable at the same time and introduce race conditions 

        each thread should try to lock and unlock the mutex when they are executing any critical section (shared resources)
          incrementing and printing the global counter variable
          after doing this , the counter should display the same value in each print statement for that same thread




    #3  
      test your understanding of threads and condition variables

      We will modifiy the program from challenge#2 so that certain threads execute critical sections of code
      before other threads do

      This program should print messages from threads that pass in an even number first ( parameter )
      ant those that pass in an odd number after all the evens have printed 
        since we are not guaranteed that the threads will start in any given order , we must have the odd
        threads wait until all the even threads have printed

      This program will require you to use condition variables to accomplish the ordering 
        all of the ood threads will sleep until a certain condition is met ( all the even threads have finished)

      Condition variables are always associated with locks because the shared information that they depend on must 
      be synchronized across threads

      You will need to use the pthread_cond_wait and pthread_cond_broadcast functions
      Your will also need a global variable that indicates when all even threads have finished
        int numer_evens_finished =  0 ; (shared data amongst threads)
        You can increment the global variable for each even thread and signal the other threads when this count
        is equal to NUM_THREADS /2 

      You can check if numbers are even by using the modulus operator 
       number % 2 == 0

      You can use the sleep(1) call after all threads have been created and are running before checking if 
      the even threads have finished 

        
*/

// Section 22 Challenge 
/*
    #1
      test your understanding of sockets and the client/server model
      Create (1 server 2 client )

      The functionality of the programs should be as follows 
        Client1 will send an interger to the server process
        the server will decrement the number and send the result to client 2
        the server should print both the value it receives and the value that it sends
        Client 2 prints te number it receives and then all the process should teminate 

        The server should be listening for numbers on a port known to the clients
          should handle the client connections sequentially and accept connections from multiple clients

        After servicing one client to completion ( Client 1 ), it should proceed to the next.





*/

int main()
{

  


  exit(EXIT_SUCCESS);

}