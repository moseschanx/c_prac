// Defining your macros here.

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
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#include <pthread.h>



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

  // Knwon problems : 
  /*
  pthread_detach 
  pthread_cancel 
  pthread_compare 
  pthread_once
  pthread_broadcast
  */
  // Try your self with the classic exmaple  "dead lock"

/*
pthread_attr_t attr1;
void* func1(void* param);
void* func2(void* param);

int main()
{

  size_t stack_size;
  pthread_t thread1 , thread2;

  pthread_attr_init(&attr1);
  pthread_attr_getstacksize(&attr1,&stack_size);
  pthread_attr_setstacksize(&attr1,stack_size*2);

  
  pthread_create(&thread1,atr1,func1,NULL);
  pthread_create(&thread2,atr1,func2,NULL);

  pthread_join(&thread1);
  pthread_join(&thread2);

  pthread_exit(NULL);

}
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


#include <sys/types.h>      //Contains definitions of a number of datatypes used in socket calls
#include <sys/socket.h>     //The main socket header file , includes a number of definitions of structures needed for sockets (socket creation , accept , listen , bind , send , recv ,etc)
#include <netinet/in.h>     //Contains constants and structures needed for internet domain addresses
#include <netdb.h>          //Defines the structure hostent
#include <arpa/inet.h>      // defines in_addr structure
#include <sys/time.h>

//The following functions are provided to fetch service name from the /etc/services file

/*
struct servent* getservbyname(char* name , char* proto)
  // takes a service name and a protocol name and returns the corresponding port number for that service

struct servent* getservbyport(int port , char* proto)
  //takes a port number and a protocol name and returns the corresponding service name  

//the returned structure : 
  struct servent{
    char* s_name;
    char** s_alias;
    int s_port;
    char* s_proto;
  }
// IP address functionality 

int inet_aton(const char* strptr , struct in_addr* addrptr)
  //converts the specified string , in the internet standard dot domain , to a network address
  // and stores the address in the structure provided

in_addr_t inet_addr(const char* strptr)
  //converts the specified string , in the internet standard dot notation , to an integer 
  //value suitable for use as an internet address

char* inet_ntoa(struct in_addr inaddr)
  //converts the specified internet host address to string in the internet standard dot notation


struct sockaddr{ // holds socket information 
//  this is a generic socket address structure , which will be passed in most of the 
//  socket function calls

  unsigned short sa_family;
  char           sa_data[14];
};
// sa_family can be the following , AF_INET , AF_UNIX , AF_NS , AF_IMPLINK
  // represents and address family 
  // in most of the internet-based applications , we use AF_INET

// sa_data is a protocol-specific address
  // we will use port number IP address , which is represented by sockaddr_in structure

struct sockaddr_in{ // helps you to reference to the socket's elements
  short int   sin_family;
  unsigned short int sin_port;
  struct in_addr sin_addr;
  unsigned char  sin_zero[8];
};

// in addr is used only in the above structure as a structure field and holds the 32bit netid/hostid
struct in_addr{
  unsigned long s_addr;
};

struct hostent{  // hostent is a structure is used to keep information related to host
  char* h_name;
  char** h_aliases;
  int h_addrtype;
  int h_length;
  char** h_addr_list;
  
  #define h_addr h_addr_list[0]
}

*/

// Steps in using sockets to communicte 
/*
    create a new socket for network communication (socket)
         to perform network io , the first thing a process must do is 
         call the socket function 
         specifying the type of communication protocol desired and protocol family
              int socket(int family , int type , int protocol)
                family  : specifies the protocol family and is usually the constant 
                          AF_INET for IPV4 protocols and AF_INETc for IPV6 protocols
                type    : specifies the kind of socket you want , and this is usually set to
                          SOCK_STREAM for a stream socket or SOCK_DGRAM for a datagram socket
                protocol : set the specific prottocol type you're using 
                          IPPROTO_TCP - TCP transport protocol
                          IPPROTO_UDP - UDP transport protocol
                          IPPROTO_SCTP - SCTP transport protocol
                      returns a socket descriptor that you can use in later system calls or -1 on error

              int setsockopt(int sockfd , int level , int optname , const void* optval ,socklen_t optlen);
                  helps manipulating options for the socket referred to by the file descriptor sockfd
                    completely optional , but it helps in reuse of address and port
                    prevents error sucha as :  "address already in use"


    attach a local address to a socket (bind)
        when a server starts up , it needs to tell the operating system which port it's gonna use
          called binding the port
        once  a server has create da socket and named it with bind() giving it an IP address and port number,
        should any program anywhere on the network give that same name to the connect() function,
        that program will find the server program and they will link up.

        int bind(int sockfd , struct sockaddr* my_addr , int addrlen);
          sockfd : a socket descriptor returned by the socket function
          my_addr : a pointer to struct sockaddr that contains the local IP address and port
            a 0 value for port number means that the system will choose a random port,
            and INADDR_ANY value for IP address means the server's IP address will be assigned automatically
          addrlen : is set to sizeof( struct sockaddr )
        
        returns 0 if it successfully binds to the address , otherwise it retruns -1 on error



    announce willingness to accept connections (listen)
              tells the OS how long you want the queue to be
              int listen(int sockfd , int backlog);
                sockfd : a socket descriptor returned by the socket function
                backlog : the max number of allowed connections
              retruns 0 on success , otherwise it retruns -1 on error

    block caller until a connection request arrives (accept)
              once you have bound a port and set up a listen queue , you then just have to ... wait
              servers spend most of their lives waiting for clients to contact them
              the accept() system calls waits until a client contancts the server , and then it 
              returns a second socket descriptor that you can use to hold a conversation on

            int accept ( int sockfd , struct sockaddr* cliaddr, socklen_t*addrlen);
                sockfd : a socket descriptor returned by the socket function
                cliaddr is a pointer to struct sockaddr that contains client IP address and port
                addrlen  : is set to sizeof(struct sockaddr)
            returns a non-negative descriptor on success , otherwise it retruns -1 on error
                all read-write operations will be done on this descriptor to communicate with the client


    actively attempt to establish a connection (connect)

              int connect(int sockfd ,strct sockaddr* serv_addr , int addrlen);
                  used by a TCP client to establish a connection with a TCP server
                sockfd :a socket decriptor returned by the socket function
                serv_addr : a pointer to struct sockaddr that contains destination IP address and port
                addrlen  : is set to sizeof(struct sockaddr)

              retruns 0 if sucessfully connect to the server , otherwise it returns -1 on error


    send some data over connection ( send)

              used to send data over stream sockets or connectedd datagram sockets
                for unconnected datagram sockets , use sendto() function
                
              int send(int sockfd ,const void* msg ,  int len , int flags);
                sockfd  : a socket descriptor returned by the socket function
                msg     : a pointer to the data you want to send
                len     : the length of the data you want to send ( in bytes)
                flags should be set to 0
                returns the number of bytes sent out , otherwise it will return -1 on error.

              int sendto(int sockfd , const void* msg , int len , unsigned int flags , const struct sockaddr* to , int tolen);
                to : a pointer to struct sockadr for the host where data has to be sent 
                tolen : should be set sizeof(struct sockaddr)
              returns the number of bytes sent , otherwise it returns -1 on error

            


    receive some data over connection ( receive )

              int recv(int sockdf , void* buf , int len , unsigned int flags);
                sockfd : a socket descriptor returned by the socket function
                buf    : the buffer to read the information into
                len    : maximum length of the buffer
                flags  : usually set to 0
              returns the number of bytes read in to the buffer , otherwise it will return -1 on error

            

    release the conenction (close )
            the shutdown functon is used to gracefully close the communication between the client and sever
            gives more control 

            int shutdown(int sockfd , int how);
              how : 0 : receiving is not allowd
                    1 : sending is not allowed
                    2 : both sending and receiving are not allowed
                    when how is set to 2 , it's the same thing as close()

          


    write :
            the write function attempts to write nbyte bytes from the buffer pointed by buf to the 
            file associated with the open file descriptor , dildes
  
            int write(int dildes , const void* buf , int nbyte);
              fildes : a socket descriptor returned byt the socket function
              buf    : a pointer to the data you want to send
              nbyte  : number of bytes to be written

            returns the number of bytes actually written to the file associated with fildes if successful
            otherwise , -1 is returned 
    read :
            attempts to read n byte bytes from the file associated with the buffer , fildes , into the buffer pointed to by buf

            int read( int fildes , const void* buf , int nbyte);
              buf : the buffer to read information into.

            returns the number of bytes actuall writen into ..... otherwise returns -1




*/

short socketCreate(void);
int bindCreateSocket(int hSocket);
int socketSend(int hSocket , char* Rq , short lenRq);
int socketReceive(int hSocket , char* Rsvp , short lenRsv);
int socketConnect(int );

int main()
{
    // Createing a server 

    int socket_desc = 0 , sock = 0 , clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char* pMessage = "hello from Jason's server";

    //Create socket
    if((socket_desc = socketCreate()) == -1)
      perror("Could not create socket!") , exit(EXIT_FAILURE);

    puts("socket created!");


    //bind
    if(bindCreateSocket(socket_desc) < 0)
      perror("bind failed!") , exit(EXIT_FAILURE);
    
    puts("bind sucess!");

    //listen
    listen(socket_desc,3);


    //accept and incoming connection
    while(1)
    {
      puts("Waiting for incoming connections ... ");
      clientLen = sizeof(struct sockaddr_in);

      // acccept connection from an incomming client
      sock = accept(socket_desc , (struct sockaddr*)&client , (socklen_t*)&clientLen);

      if(sock < 0)
        perror("accept failed") , exit(EXIT_FAILURE);

      puts("connection accepted");

      memset(client_message, '\0',sizeof(client_message));
      memset(message , '\0', sizeof(message));

      //receive a reply from the client 
      if((recv(sock , client_message , 200 , 0))<0)
      {
        perror("receive failed ");
        break;
      }

      printf("client reply : %s\n",client_message);

      if(!strcmp(pMessage,client_message))
        strcpy(message,"Hi , there");
      else
        strcpy(message , "Invalid Message");

      // send some data
      if(send(sock,message,strlen(message),0) < 0)
        perror("send failed!") , exit(EXIT_FAILURE);

      close(sock);
      sleep(1);

      
    }

    exit(EXIT_SUCCESS);

      
}
int client_main()
{
  //create a client
  int hSocket = 0 , readSize = 0;
  struct sockaddr_in server;
  char send_to_server[100] = {0};
  char server_reply [200] = {0};

  //create a socket 
  if((hSocket = socketCreate())==-1)
    perror("Could not create socket") , exit(EXIT_FAILURE);

  puts("Socket is created");

  //connect to remote server
  if(socketConnect(hSocket)<0)
    perror("connect failed ") , exit(EXIT_FAILURE);

  puts("Successfully connected with server ");
  printf("Enter your messages:");
  fgets(send_to_server , 100 , stdin);

  //send message to server 
  socketSend(hSocket,send_to_server,strlen(send_to_server));

  //receive the data from the server 
  readSize = socketReceive(hSocket,server_reply,200) ;
  printf("Reply from server : %s \n",server_reply);
  
  close(hSocket);


}

short socketCreate(void)
{
  short hSocket = 0;
  printf("Create the socket \n");
  hSocket  = socket(AF_INET , SOCK_STREAM , IPPROTO_IP);
  return hSocket;
}

int bindCreateSocket(int hSocket)
{
  int iRetval = -1;
  int clientPort = 12345;

  struct sockaddr_in remote = {0};
  remote.sin_family = AF_INET;

  remote.sin_addr.s_addr = htonl(INADDR_ANY);
  remote.sin_port = htons(clientPort);

  iRetval = bind(hSocket,(struct sockaddr*)&remote , sizeof(remote));
  return iRetval;
  
}

int socketConnect(int hSocket)
{
  int iRetval = -1;
  int ServerPort = 12345;

  struct sockaddr_in remote = {0};
  remote.sin_addr.s_addr = inet_addr("127.0.0.1");
  remote.sin_family = AF_INET;
  remote.sin_port = htons(ServerPort);

  iRetval = connect(hSocket ,(struct sockaddr*)&remote , sizeof(remote));
  return iRetval;

}

int socketSend(int hSocket , char* Rq , short lenRq)
{
  int shortRetval = -1;
  struct timeval tv;
  tv.tv_sec = 20;
  tv.tv_usec = 0;

  if(setsockopt(hSocket , SOL_SOCKET , SO_SNDTIMEO , (char*)&tv , sizeof(tv))<0)
    perror("send failure : time out") , exit(EXIT_FAILURE);

  shortRetval = send(hSocket,Rq,lenRq,0);

  return shortRetval;

}

int socketReceive(int hSocket , char* Rsvp , short lenRsv)
{
  int shortRetval = -1;
  struct timeval tv;
  tv.tv_sec = 20;
  tv.tv_usec = 0;

  if(setsockopt(hSocket , SOL_SOCKET , SO_RCVTIMEO, (char*)&tv , sizeof(tv))<0)
    perror("receive failure : time out") , exit(EXIT_FAILURE);

  shortRetval = recv(hSocket,Rsvp,lenRsv,0);
  printf("Response : %s ",Rsvp);

  return shortRetval;

}