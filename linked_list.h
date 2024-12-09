#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct {
    size_t size;
    node* head;
} linked_list;

// Function declarations
node* make_node(int value);
linked_list make_list();
void free_list(linked_list l);
void append(linked_list* l, int value);
void push(linked_list* l, int value);
int pop_last(linked_list* l);
int pop(linked_list* l);
int get(linked_list l, size_t index);
void set(linked_list l, size_t index, int value);
void print_list(linked_list l);

#endif // LINKED_LIST_H
