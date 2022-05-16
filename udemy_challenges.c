
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <complex.h>
#include <stdbool.h>
#include <setjmp.h>

// Challenge #1 ( using variable length arrays )

// Example : 
// Input elements : 10,20,30,40,50
// Output 
// Sum of all elements = 150
int Challenge1(){

    #ifdef __STDC_NO_VAL__
        printf("Your compiler does not supoort VLA!\n");
        exit(1);
    #endif

    size_t ary_sz;
    printf("Input the array size : ");
    scanf("%zi",&ary_sz);
//    size_t* elem_ary = malloc(ary_sz*sizeof(size_t));
    size_t elem_ary[ary_sz];
    printf("Input %zi element(s) :\n",ary_sz);

    for(size_t i = 0;i<ary_sz;++i)
        scanf("%zi",&elem_ary[i]);

    for(size_t i = 0; i<ary_sz;++i)
        printf("%d\n",elem_ary[i]);

    return 0;
}

// Challenge #2 (flexible array members)
/*
    1. create a structure named myArray that has a length
    member and a flexible array member named array

    2. read in from the user the size of array at runtime

    3. allocate memory for structure based on this size 

    4. set the length member and fill the array with some dummy data

    5. print te array elements

*/

typedef struct {
    size_t sz;
    size_t array[];
}chlg_struct;

int Chanllenge2(){

    chlg_struct* s1;

    
    size_t desired_sz;
    puts("Input the size of the array : ");
    scanf("%zi",&desired_sz);

    s1 = malloc(sizeof(chlg_struct)+sizeof(size_t)*desired_sz);
    // sizeof(chlg_struct) : the size of the struct except FAM. 
    s1->sz = desired_sz;

    for(int i=0;i<s1->sz;++i)
        s1->array[i] = random();

    for(int i=0;i<s1->sz;++i)
        printf("The %dth element in array :%zi\n",i,s1->array[i]);

}

// Challenge #3
/*

    1. Create a double compelx number with the imaginary number squared
    using the multiplication operator (| * |)
        Display as ouput the real number and the imaginary number.
    
    2. Create a double complex number with the imaginary number squared
    using the pow function from the math library (pow(i,2))
        Display ...

    3. Create a double complex number that performs Euler's formula.
        PI = acos(-1)
        the complex number is the exponent of I * PI
        Display ...

    4. Create a double complex number that performs a conjugate.
        a complex number that is 1+2*I
        a complex number that is 1-2*I
        Display ...


        



*/

int Challenge3(){


    #ifdef __STDC_NO_COMPLEX__
        printf("No support for Complex numbers!");
        exit(1);
    #endif

    #ifndef __STDC_IEC_559_COMPLEX__
        puts("Imaginary number not supported ");

    #endif


    // Imaginary number is not supported in clang 
}



int convertBinToDec(long long n){

    int decimalReuslt = 0 , i = 0 , remainder = 0;

//    for(;n>0;++i,remainder = n%10,n/=10;)

    while(n>0){
        remainder = n%2;
        n /= 10;
        decimalReuslt += pow(2,i);
        ++i;
    }

   return decimalReuslt; 

}

long long convertDecToBin(int n){

    int binResult = 0 , i = 1 , remainder = 0;

    while(n>0){

        remainder = n % 2;
        n /= 2;
        binResult += remainder * i;
        i *= 10;

    }

    return binResult;
}

int binChallenge(){ 

//int main(){

/*
    int decIn = 0;
    printf("Please entere decimal number to convert :");
    scanf("%d",&decIn);
    printf("\nThe corresponding binary number is : %lld",convertDecToBin(decIn));

*/
    long long binIn = 0;
    printf("Please entere binary number to convert :");
    scanf("%lld",&binIn);
    printf("\nThe corresponding decimal number is : %d",convertBinToDec(binIn));

    return 0;

}


// Setting and reading bit 
/* write a C program to input any number from a user
    the program should check wherether nth bit of the given number is set or not
    the program should set nth bit of the given number as 1

    exmaple :
        Enter any number : 10
        Enter nth bit to check and set ( 0 - 31) : 2

*/
int seReBits(){


    int numIn , nthBit , bitStatus;
    printf("Enter any number : ");
    scanf("%d",&numIn);

    printf("Enter (n)th bit to check and set (0-31) : ");
    scanf("%d",&nthBit);
    
    bitStatus = (numIn >> nthBit) & 1;
    printf("The (%d)th bit is %d\n",nthBit,bitStatus); 
    numIn |= (1 << nthBit);
    printf("Bit was set successfully and eventually is : %d\n",numIn);
    
    return 0;

}

// Using bit fields to pack data.
/*

    Write a program that contains the following bit fields in a structure (on screen box)
        the box can opaque or transparent 
        a fill color is selected from the following palette of colors : 
            black , red , green , yellow , blue , megenta , cyan , or white
        a border can be shown or hidden 
        a border color is selected from the same palette used for the fill color
        a border can use one of three line styles - solid , dotted , or dashed.


*/

// Line styles 
#define SOLID 0
#define DOTTED 1
#define DASHED 2

// Base colors 
#define BLUE 4
#define GREEN 2
#define RED 1
#define BLACK 0

// derived colors 
#define YELLOW (RED|GREEN)
#define MEGENTA (RED|BLUE)
#define CYAN    (GREEN|BLUE)
#define WHITE   (RED|BLUE|GREEN)

const char* colors[] = {"black","red","green","yellow","BLUE","megenta","cyan","white"};


typedef struct {
    unsigned int opaque       : 1;
    unsigned int color        : 3;
    unsigned int              : 4;
    unsigned int border       : 1;
    unsigned int border_color : 3;
    unsigned int border_style : 2; 
    unsigned int              : 2;
}onScreen_box;

void show_settings(onScreen_box* pb){

    printf("Opacity : %s\n",pb->opaque ? "True":"False");
    printf("Color : %s\n",colors[pb->color]);
    printf("Border : %s\n",pb->border ? "True" : "False");
    printf("Border color : %s\n",colors[pb->border_color]);
    printf("Border style : ");

    switch(pb->border_style){
        case 00: puts("SOLID"); break;
        case 01: puts("DOTTED"); break;
        case 02: puts("DASHED"); break;
    
    }

}

int bit_packData(){

    onScreen_box box = {true , BLACK , false , YELLOW , SOLID};


    puts("Original box settings :");
    show_settings(&box);


    box.border = true;
    box.opaque = false;
    puts("\nModified box settings :");
    show_settings(&box);

}

//Challenge (setjmp and longjmp)
/*

    Create a function named error_recovery that prints out an error 
    and then uses longjmp to transfer control back to a main function loop

    Your main function should include a forever loop that uses setjmp at the top
    of the loop before processing 

    You can add "dummy" code in your loop that simulates an error 
    (by calling error_recover) when setjmp returns 0




*/

jmp_buf buf;

void error_recovery(){

    puts("Error!");
    longjmp(buf,1);

}
int main(void) {

    if(setjmp(buf))
        puts("Welcome back!");
    else{
        puts("Hello");   
        error_recovery();
    }
    puts("Program exit.");
  
  return 0;
}

// Section 10 Challenge #1
/*
    Objectives : understand the common char I/O functions.

    count the number of words and characters in a file / from stdin
    
    0/1 arugment is allowed.
        0 : If there is no argumnt , stdin is to be used for input.
        1 : If there is one argumnt , it's interpreted as the name of a file.

    
*/


int sec10_cha1(int argc , char** argv) // problem : need some tiny fixes on words counting.
//int main(int argc , char** argv) 
{

    if(argc == 1){
        FILE* fp = fopen("default_file.txt","w+");
        char ch;
        int cnt_word =0 , cnt_char =0 , cnt_line =0;
        while((ch = fgetc(stdin))!=EOF){
            // Algorithm pending implement.
            if(ch == ' ')++cnt_word;
            else if(ch == '\n')++cnt_line;
            else
                ++cnt_char;
            fputc(ch , fp);

        }
        printf("The number of words in the file : %d\n",cnt_word);
        printf("The number of characters in the file : %d\n",cnt_char);
        printf("The number of lines in the file : %d\n",cnt_line);

    }else if(argc == 2){

        FILE* fp = fopen(argv[1],"w+");
        char ch;
        int cnt_word =0 , cnt_char =0 , cnt_line =0;
        while((ch = fgetc(stdin))!=EOF){
            // Algorithm pending implement.
            if(ch == ' ')++cnt_word;
            else if(ch == '\n')++cnt_line;
            else
                ++cnt_char;
            fputc(ch , fp);

        }
        printf("The number of words in the file : %d\n",cnt_word);
        printf("The number of characters in the file : %d\n",cnt_char);
        printf("The number of lines in the file : %d\n",cnt_line);

}

// Section 10 Challenge #2
/*
    Objectives : understand fgetc() and fputc() 

    write a c program to convert uppercase to lowercase and vice versa in file
        this program can take a command-line argument for the name of the file 
        or you can ask the user for the name of the file.
    You'll need a to create a temporary file to store the result( character converted )
        can then rename it back to the original file.
    
*/

int sec10_cha2(int argc , char** argv)
//int main(int argc , char** argv)
{

   char* file_name = NULL;
   char* file_name_fina = NULL;
    FILE* fp_orig = NULL;
    FILE* fp_fina = NULL;
    
    if(argc == 1){

        file_name = "default.txt";
        file_name_fina = "default_fina.txt";
        fp_orig = fopen(file_name,"w+");
        fp_fina = fopen(file_name_fina,"w+");
        

        char ch;
        while((ch = fgetc(stdin))!=EOF){
            fputc(ch,fp_orig);
        }

        rewind(fp_orig);
        while((ch = fgetc(fp_orig))!=EOF){
            if(isupper(ch)) ch=tolower(ch);
            else if(islower(ch)) ch=toupper(ch);
            fputc(ch,fp_fina);
        }

        if(ferror(fp_orig) || ferror(fp_fina)){
            perror("File Stream Error");

        }else{
            puts("End of file reached , program exit.");
            rename(file_name_fina,file_name);
            fclose(fp_fina);
            fclose(fp_orig);
            exit(EXIT_SUCCESS);
        }
        

    }else if(argc == 2){
        
        file_name = (char*)malloc(sizeof(argv[1]+1));
        strcpy(file_name,argv[1]);
        assert(strncat(argv[1],"_",1));
        file_name_fina = (char*)malloc(sizeof(argv[1]+2));
        

        strcpy(file_name_fina,argv[1]);


        fp_orig = fopen(file_name,"w+");
        fp_fina = fopen(file_name_fina,"w+");
        

        char ch;
        while((ch = fgetc(stdin))!=EOF){
            fputc(ch,fp_orig);
        }

        rewind(fp_orig);
        while((ch = fgetc(fp_orig))!=EOF){
            if(isupper(ch)) ch=tolower(ch);
            else if(islower(ch)) ch=toupper(ch);
            fputc(ch,fp_fina);
        }

        if(ferror(fp_orig) || ferror(fp_fina)){
            perror("File Stream Error");

        }else{
            puts("End of file reached , program exit.");
            rename(file_name_fina,file_name);
            fclose(fp_fina);
            fclose(fp_orig);
            exit(EXIT_SUCCESS);
        }

    }else{
        
    }
    

}

// Section 10 Challenge #3
/*
    Objectives : understand common String I/O functions.
    
        Write a program that takes two command-line arguments
            The first is a character
            The second is a filename

        Print only those lines in the file containing the given character 
            lines in a file are identified by a terminating  '\n'
            assume that no line is more than 256 characters long

        use fgets() getline() for reading the file
        use puts to display the output 


*/

bool dsir_chk(char* buf , char* dsir_ch){

    for(int i = 0;i<sizeof(buf);++i){
        if(buf[i] == *dsir_ch) return true;
    }
    return false;

}
int sec10_cha3(int argc, char** argv)
//int main(int argc , char** argv)
{

    if(argc!=3) perror("Parameter list Error.") , exit(EXIT_FAILURE);

    char *dsir_ch  = argv[1] , *file_name = argv[2];

    FILE* fp = fopen(file_name,"r+"); assert(fp);

    int buf_sz = 256;
    char* buf[buf_sz];
    while(!feof(fp)){
        fgets(buf , sizeof(buf),fp);
        //getline(&buf,&buf_sz,fp); // problems
        if(dsir_chk(buf,dsir_ch)) puts(buf);
    }

    if(feof(fp)){ puts("File EOF reached, program exit."); } return 0;

}

// Section 10 Challenge #4
/*
    Objectives : understand common formatting I/O functions

        write a program that takes as input, a set of numbers from a file
        and write even , odd and prime numbers to standard output.
        
        use fscanf fgets and sscanf to accomplish 


*/
int sec10_cha4()
//int main(int argc , char** argv)
{

    if(argc < 2) perror("Too few arguments") , exit(EXIT_FAILURE);
    char* file_name = argv[1];
    FILE* fp = fopen(file_name,"r+");
    assert(fp);

    char buf[256];
    int x1 , x2 , x3 , x4;

    while(!feof(fp))
    {
    fgets(buf,sizeof(buf),fp);
    sscanf(buf,"%d %d %d %d",&x1,&x2,&x3,&x4);
    printf("%d\t%d\t%d\t%d\n",x1,x2,x3,x4);
    }
   return 0; 
}


// Section 11 : challenge 1 
    // Create your own prinf function using variadic functions

void revert_str(char* des , char* src);
void myitoa(long num,char* str);
void myprintf( char* fmt , ...);

int sec11_cha1(){
//int main(){
    
    myprintf("This is a number %d , and a string %s ",42,"Hello, World!\n");

    return 0;

}

void revert_str(char* des , char* src)
{

   int src_len = 0;
    while(*src != '\0') ++src , ++src_len;
    src -= src_len;

    for(int i=0;i<src_len;++i)
    {
        des[src_len-1-i] = src[i];
    }
    des[src_len] = '\0';
}

void myitoa(long num,char* str)
{
    while(num>0)
    {
        *str++ = num%10 + 48;
        num /= 10;
    }
    *str = '\0';
}

void myprintf( char* fmt , ...)
{

    char str[256],str_rev[256];
    va_list args;
    va_start(args,fmt);

   while(*fmt != '\0')
   {
    if(*fmt == '%')
    {
        switch(*++fmt)
        {
        case 'd' :
            myitoa(va_arg(args,int),str);
            revert_str(str_rev,str);
            fputs(str_rev,stdout);
            break;

        case 'c' :
            fputc(va_arg(args,char),stdout);
            break;
           
        case 's' :
            fputs(va_arg(args,char*),stdout);
            break;
        }
        ++fmt;
    }else
    {
        fputc(*fmt,stdout);
        ++fmt;
    }
    }

    va_end(args);

}

// Section 11 challenge #2 :
    /* 
    write a program to claculate the sum of numbers from
     1 to n using recursion.

     Sample input / output : 
        Input the last number of range starting from 1:5
        the sum of numbers from 1 to 5 : 
        15

    write a program which will find GCD ( greatest common denominator )
    of two numbers using recursion 

     Sample input / output : 
        Input 1st number : 10
        Input 2nd number : 50

        The GCD of 10 and 50 is : 10


    write a progam which will find reverse a string using recursion 

     Sample input / output : 
        Enter the string : studytonight 

        The orignal string is : studytonight 
        The reverse string si : thginostyduts

    */

long rec_sum(int n){
    if(n == 0) return 0;
    return (n+rec_sum(n-1));
}

int find_gcd(int n1 , int n2)
{
    if(n1>n2){
        
        if(n1%n2 == 0) return n2;
        else
            return find_gcd(n1,n2/2);

    }else if(n1<n2){

        if(n2%n1 == 0) return n1;
        else
            return find_gcd(n2,n1/2);

    }else if(n1 == n2){

        return n1;
        // or return n2 , this case they're both equal.

    }else{
        return 1;
    }

}

char* reverse_string(char* str)
{
    static int i = 0;
    static char res[256];
    //if(str == NULL){ perror("String notcorrect ") ; return NULL; } 

    if(*str)
    {
        reverse_string(res+1);
        res[i++] = *str;
    }
//res[i++] =  *(reverse_string(++str));

    return res;
}
int sec11_cha2() // problem at string reversal , maybe paltform issue?
//int main() 
{

    printf("Test recursion : %ld\n",rec_sum(5));

/* find gcd of two numbers */
/*
    int num1 , num2;
    printf("Inpuit 1s number : ");
    scanf("%d",&num1);

    printf("Inpuit 2s number : ");
    scanf("%d",&num2);

    printf("The gcd of %d and %d is %d",num1,num2,find_gcd(num1,num2));

*/
/* find reverse string from input */

    char str[256];
    char *rev = NULL;
    printf("Input some string to reverse : ");
    scanf("%s",&str);

    rev = reverse_string(str);
    printf("Reversed string of %s is : %s \n",str,rev);
    return 0;
}

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
    y C
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
int sec14_cha1to4()
//int main()
{
    //Challenge #1
    printf("__LINE__ is : %d\n",__LINE__);
    printf("__FILE__ is : %s\n",__FILE__);
    printf("__DATE__ is : %s\n",__DATE__); 
    printf("__TIME__ is : %s\n",__TIME__);
    printf("__STDC__ is : %d\n",__STDC__);
    //

    //Challenge #2
#define SUM_OF_TWO(param1,param2) ((param1)+(param2))

    	int num1,num2;
	printf("Please input two numer to get sum (by using macro) :");
	scanf("%d%d",&num1,&num2);

	printf("Your sum is : %d",SUM_OF_TWO(num1,num2));

    //
    
    //Challenge #3
#define CUBE(param) ((param)*(param)*(param))
#define SQUARE(param) ((param)*(param))
   	int num3; 
	printf("Enter any number to find square and cube :");
	scanf("%d",&num3);

	printf("Square of %d is : %d \n",num3,SQUARE(num3));
	printf("Cube of %d is : %d \n",num3,CUBE(num3));


    //


    //Challenge #4
#define IS_UPPER(param) (((param)<=90 && (param)>=65) ? 1 : 0)
#define IS_LOWER(param) (((param)<=122 && (param)>=97) ? 1 : 0)
#define IS_ALPHANUMERIC(param) (((param)<=57 && (param)>=48) ? 1 : 0)
#define IS_CONTROL(param) (((param)<=31 && (param)>=0) ? 1 : 0)
#define IS_SPACE(param) (((param == 32) ? 1 : 0))
#define IS_NEWLINE(param) (((param == '\n') ? 1 : 0))


#define CHECK(param) \
if(IS_UPPER(param))\
printf("%c is uppercase :",param);\
else if(IS_LOWER(param))\
printf("%c is lowercase :",param);\
else if(IS_ALPHANUMERIC(param))\
printf("%c is alphanumeric :",param);\
else if(IS_CONTROL(param))\
printf("%c is control :",param);\
else if(IS_SPACE(param))\
printf("%c is space :",param);\
else if(IS_NEWLINE(param))\
printf("%c is new line:",param);\
else \
printf("%c is not in the ASCII table :",param);\

    char c;
    printf("Enter nay character :");
    scanf("%c",&c);
    CHECK(c);

    //
    
    return 0;

}


