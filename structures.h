#ifndef _STRUCTURE_H
#define _STRUCTURE_H

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;

}node;



void init_list(node**,int);
 
void insert_node_begin(node**,int);

void insert_node_trail(node**,int);

void insert_node_anypos(node**,int,int);

void update_node(node**,int,int);

int* search_node(node**,int);

void display_list(node*);

void display_poses(int* res);

/*! Initialize a stack 
*  @param   stack_begin beginning node of the stack 
*  @param   data        The data to be initialized to node
*
*  @return              
*/
void init_stack();

/*! Initialize a stack 
*  @param   
*
*  @return              
*/
void clear_stack();

/*! Push onto stack , this will create a node inside the stack.
*  
*
*  @return              
*/
void push_stack(int data);

/*! Pop form stack , this will destroy a node inside the stack.
*
*  @return  Data from top of the stack            
*/
int pop_stack();


/*! Check if the stak is empty
*
*  @return Empty 1 , Not empty 0
*/
bool is_stack_empty();

/*! Get the top stack node value.
*
*  @return  The data which top stack node posses.
*/
int peek_stack();

/*! Display the whole stack from the beginning.
*
*  @return  
*/
void display_stack();



void init_queue(int data);

void in_queue(int data);

int de_queue();

void clear_queue();

bool is_queue_empty();

int peek_queue();

void display_queue();

#ifdef __cplusplus
    }
#endif

#endif