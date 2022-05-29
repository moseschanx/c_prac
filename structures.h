#ifndef _STRUCTURE_H
#define _STRUCTURE_H

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct node {
    int data;
    struct node* next;

}node;


void init_list(node**,int);
 
void insert_node_begin(node**,int);

void insert_node_trail(node**,int);

void insert_node_anypos(node**,int,int);

void update_node(node**,int,int);

int* search_node(node**,int);

void display_list(node*);

void display_poses(int* res);

#ifdef __cplusplus
    }
#endif

#endif