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

#ifdef DEBUG
  #define PRINTF(...) printf(__VA_ARGS__)
#endif

volatile sig_atomic_t gSignalStatus;

// void (*signal(int , void (*handler)(int))) (int);

static void hdl( int sig , siginfo_t* siginfo , void* context)
{

  printf("Signal ID %d \n",sig);
  printf("Siginfo : si_signo %d \n",siginfo->si_signo);
  printf("Siginfo : si_errorno %d \n",siginfo->si_errno);
  printf("Siginfo : si_code %d \n",siginfo->si_code);
  printf("Siginfo : si_pid %d \n",siginfo->si_pid);
  printf("Siginfo : si_uid %d \n",siginfo->si_uid);
  printf("Siginfo : si_status %d \n",siginfo->si_status);
  printf("Siginfo : si_addr %d \n",siginfo->si_addr);
  /*
  printf("Siginfo : si_signo %d \n",siginfo->si_signo);
  printf("Siginfo : si_signo %d \n",siginfo->si_signo);
  printf("Siginfo : si_signo %d \n",siginfo->si_signo);
  */

}

void signal_handler(int signal)
{

  printf("\nInterrupt signal ( %d ) received.\n",signal);

}
void childProcess();
void parentProcess();
int main()
{
  
/*
    struct sigaction sa , old_sa;

    sa.sa_handler = signal_handler;
    
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT , NULL , &old_sa);
    // Check if any of those signals in the past we're set to ignore.
    if(old_sa.sa_handler != SIG_IGN) //Query Actions
      if(sigaction(SIGINT , &sa , NULL)<0)
        perror("Sigaction Error");

    sigaction(SIGHUP, NULL , &old_sa);

    if(old_sa.sa_handler != SIG_IGN)
      if(sigaction(SIGHUP, &sa , NULL)<0)
        perror("Sigaction Error");

    sigaction(SIGTERM, NULL , &old_sa);

    if(old_sa.sa_handler != SIG_IGN)
      if(sigaction(SIGTERM , &sa , NULL) <0)
        perror("Sigaction Error");
    
  return 0;

*/
/*
  struct sigaction sa;

  sa.sa_sigaction = hdl;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_SIGINFO;

  if(sigaction(SIGINT , &sa ,NULL) <0 )
    perror("Sigaction error") , exit(EXIT_FAILURE);


  while(true);
  
*/

/*

    pid_t pid;
  
    pid = fork();

    if(pid == 0) // In the forked process , the fork() will return 0. 
      childProcess(pid);
    if(pid > 0) // In the parent process , the fork() will return the pid of froked process ( child ). 
      parentProcess(pid);
    else
      perror("Fork error") , exit(EXIT_FAILURE);

    exit(EXIT_SUCCESS);

  */  


  
  
}
void childProcess(pid_t pid)
{
  char buf[256];
  for(int i = 1 ; i < 10; ++i)
  {
    sprintf(buf,"This is from the child , value : %d\n" , i);
    write(1,buf,strlen(buf));
    sleep(1);

  }
}
void parentProcess(pid_t pid)
{
  char buf[256];
  for(int i = 1 ; i < 10; ++i)
  {
    sprintf(buf,"This is from the parent , value : %d\n" , i);
    write(1,buf,strlen(buf));
    sleep(1);

  }
}


// Phtread practice exmaple code :
    pthread_attr_t attr;
    pthread_mutex_t lock; 
    //pthread_mutex_init(&lock,NULL);
    pthread_cond_t cond;
    // cond = PTHREAD_COND_INITIALIZER; (statically declared)
    //pthread_cond_init(cond); ( dynamically created )

typedef struct thread_param
{
  int id;
  char* msg;

}thread_param;

void* print_message(void* param)
{

  
    size_t stack_size;
    pthread_attr_getstacksize(&attr, &stack_size);
    printf("Default stack size %zu \n",stack_size);

  thread_param* t_param = (thread_param*)param;
  printf("Id : %d Message : %s \n",t_param->id ,t_param->msg);

  printf("This message is form within the thread : %d\n",(int)pthread_self());
  return t_param->msg;
  

}

int main() // Play around with Pthread functions.
{

    pthread_t thread1 , thread2;
    thread_param* t_param = malloc(sizeof(thread_param));

    size_t stack_size;

    // when no longer needed 
    pthread_mutex_destroy(&lock);
    // Locking mechanisim
    pthread_mutex_lock(&lock);
    pthread_mutex_trylock(&lock);
    
    pthread_mutex_unlock(&lock);
    

    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stack_size);
    printf("Default stack size %zu \n",stack_size);

    stack_size = 1048576;

    pthread_attr_setstacksize(&attr, stack_size);


    t_param->id = 99;
    t_param->msg = "This is From param structure ";
    

    char* ret_msg;
    int pret1 , pret2;
 
    pret1 = pthread_create(&thread1,&attr,print_message,(void*)t_param);

    pthread_join(thread1,(void**)&ret_msg);

    if(pret1 == 0)
      puts("Pthread creation success.");
    else
      perror("Pthread creation error .");
    

    pthread_exit(NULL);

    exit(EXIT_SUCCESS);





}
