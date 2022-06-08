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

typedef struct tree_node {
    int data;
    struct tree_node* parent;
    struct tree_node* lchild;
    struct tree_node* rchild;

} tree_node;

// List
void init_list(node**,int);
 
void insert_node_begin(node**,int);
void insert_node_trail(node**,int);
void insert_node_anypos(node**,int,int);

void update_node(node**,int,int);

int* search_node(node**,int);
void display_poses(int* res);

void display_list(node*);
void display_list_backward(node* n_last);
// Stack
void init_stack();

void clear_stack();

void push_stack(int data);

int pop_stack();

bool is_stack_empty();

int peek_stack();

void display_stack();
// Queue 
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