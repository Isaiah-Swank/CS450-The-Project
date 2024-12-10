#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
Node* insertNode(Node* head, int data);
Node* findNode(Node* head, int target);
void freeList(Node* head);

#endif // LINKED_LIST_H