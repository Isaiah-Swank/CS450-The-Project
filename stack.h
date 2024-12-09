#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#define STACK_CAP 100

// Array-based stack structure
typedef struct {
    int data[STACK_CAP];
    size_t size;
} stack_array;

// Linked list node structure
typedef struct node {
    int value;
    struct node* next;
} node;

// Linked list-based stack with head structure
typedef struct {
    size_t size;
    node* head;
} stack_ll;

// Function declarations for array-based stack
void push_stack_array(stack_array* stack, int elem);
int pop_stack_array(stack_array* stack);
int peek_stack_array(stack_array* stack);
int empty_stack_array(stack_array* stack);

// Function declarations for headless linked list stack
node* make_list(int value);
void push_stack_nhll(node** stack, node* x);
node* pop_stack_nhll(node** stack);
int peek_stack_nhll(node** stack);
int empty_stack_nhll(node** stack);

// Function declarations for headed linked list stack
void push_stack_hll(stack_ll* stack, int x);
int pop_stack_hll(stack_ll* stack);
int peek_stack_hll(stack_ll* stack);
int empty_stack_hll(stack_ll* stack);

#endif // STACK_H
