#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structures.h"

void init_list(node** n , int data)
{
    (*n)->next = NULL;
    (*n)->data = data;
}

void insert_node_begin(node** n_begin,int data)
{
    node* add_begin =  (node*)malloc(sizeof(node));
    add_begin->data = data;
    add_begin->next = *n_begin;
    *n_begin = add_begin;
}

void insert_node_trail(node** n_begin,int data)
{
    node* add_trail = (node*)malloc(sizeof(node));
    add_trail->data = data;
    add_trail->next = NULL;

    // Why create another pointer in this function ? 
    // Because we have used double pointer here , thus every time you made chagne
    // to this pointer , you will change  where the node pointer points to in the outside scope.
    // And for the reason that the outside node pointer should never 
    // be modified in this function, so we must create a local node pointer to prevent outside 
    // pointer to be  modified. 
    node* ptr = *n_begin;     
    for(;ptr->next!=NULL;ptr=ptr->next);
    ptr -> next = add_trail;
}

void insert_node_anypos(node** n_begin,int pos,int data)
{

    if((*n_begin)->next==NULL){
        puts("This feature is not implemented,\n\
        please use insert_node_begin/trial instead.");
        return;
    }
    node* lptr = *n_begin; // Pointer to the left node of your insertion.
    for(;pos!=1 && lptr->next != NULL;lptr=lptr->next,--pos);

    node* rptr = lptr->next; // Pointer to the right node of your insertion.

    node* add_node = (node*)malloc(sizeof(node));
    add_node->data = data;
    
    lptr -> next = add_node; // Insertion operations.
    add_node -> next = rptr;

}

void update_node(node** n_begin,int pos,int data)
{
    node* ptr = *n_begin;
    if(ptr->next == NULL)
    {
        ptr->data = data;
        return;
    }
    
    for(;pos!=1;--pos,ptr=ptr->next) // Take the local node pointer to the desired position.
        if(ptr->next==NULL) // When you're not reached your desired position, the last node should never be reached in this loop.
            ptr->data=data , puts("List lengthh exceeded , set data to the last node");
    ptr->data = data;

            
    
}

int* search_node(node** n_begin,int data)
{
    int pos=1 , cnt = 0 , i;
    node* ptr = *n_begin;
    for(;ptr->next != NULL;ptr = ptr->next) // Get the count of searched position. 
        if(ptr->data == data) ++cnt,++pos;  
        else ++pos;

    if(cnt==0) return NULL;

    if(cnt>1){
        int* res = calloc(cnt+1,sizeof(int)); // Reserve an array on heap memory ( for storage duration)
        
        for(i=0, pos = 1,ptr = *n_begin;ptr->next != NULL;++pos,ptr = ptr->next) 
        if(ptr->data == data) res[i++] = pos;

        res[cnt] = EOF; // Detection point 

        return res;
    }
        
    return (int[]){pos};

}

void display_poses(int* res)
{       
        if(res == NULL)
            puts("Did not searched anything!");
        printf("Searched at postion :");
        while(*res != EOF){ // Detection point
            printf("%d ",*res++);
        }
        puts("");
        
}

void display_list(node* n_begin)
{
    if(n_begin->next==NULL){
        printf("node #1 , data : %d \n",n_begin->data);
        puts("list end reached !\n");
        return;
    } // If the linked list only has one node.


    int pos = 1;
    do{
        printf("node #%d , data : %d \n",pos,n_begin->data);
        ++pos , n_begin = n_begin->next;

        
    }while(n_begin->next!=NULL); // Print out nodes before the last node.
    printf("node #%d , data : %d \n",pos,n_begin->data); // Print the last node

    puts("list end reached !\n");

}

node* stack_begin=NULL;
node* stack_ptr=NULL;

void init_stack(int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    stack_begin = new_node;
    stack_ptr = stack_begin;
  
}

void push_stack(int data)
{
    node* add_node = (node*)malloc(sizeof(node));
    add_node->next = NULL;
    add_node->data =  data;

    stack_ptr->next = add_node;
    stack_ptr = add_node;
}

int pop_stack()
{
    // return data part
    if(is_stack_empty()) return 0;
    int data = stack_ptr->data; 

    /* 
    *   
    */  
    node* ptr = stack_begin->next;
    node* prev_ptr = stack_begin;
    for(;ptr->next!=NULL;prev_ptr=ptr,ptr=ptr->next);
    free(ptr);
    prev_ptr->next=NULL;
    stack_ptr = prev_ptr;

    return data;
}

int peek_stack()
{
    return stack_ptr->data;
}

void clear_stack()
{
    node* prev_ptr = stack_begin;
    node* ptr = stack_begin->next;

    for(;ptr->next!=NULL;prev_ptr=ptr,ptr=ptr->next)
            free(prev_ptr);

    free(ptr);
}

bool is_stack_empty()
{
    return (stack_ptr->data==0&&stack_ptr->next==NULL) ? true : false;
} 


void display_stack()
{
    if(!is_stack_empty())
        display_list(stack_begin);
    return;
}

node* queue_begin;
node* queue_ptr;

void init_queue(int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    queue_begin = new_node;

}

void in_queue(int data)
{
    node* add_node = (node*)malloc(sizeof(node));
    add_node->prev = NULL;
    add_node->data =  data;

    queue_ptr->prev = add_node;
    queue_ptr = add_node;
}

int de_queue()
{
    // return data part
    if(is_stack_empty()) return 0;
    int data = queue_ptr->data; 

    /* 
    *   
    */  
    node* ptr = queue_begin->prev;
    node* prev_ptr = queue_begin;
    for(;ptr->next!=NULL;prev_ptr=ptr,ptr=ptr->prev);
    free(ptr);
    prev_ptr->prev=NULL;
    queue_begin = prev_ptr;

    return data;
  
}

void clear_queue()
{
    node* prev_ptr = queue_begin;
    node* ptr = queue_begin->prev;

    for(;ptr->next!=NULL;prev_ptr=ptr,ptr=ptr->prev)
            free(prev_ptr);

    free(ptr);

}

bool is_queue_empty()
{

    return (queue_ptr->data==0&&queue_ptr->next==NULL) ? true : false;
}

int peek_queue()
{
    return queue_ptr->data;
}

void display_queue()
{
    if(!is_queue_empty())
        display_list(queue_begin);
    return;

}