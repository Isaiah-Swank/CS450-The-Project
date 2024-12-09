#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdlib.h>

#define B 0 // Black
#define R 1 // Red

typedef struct node {
    int value;
    int color;
    struct node* parent;
    struct node* left;
    struct node* right;
} Node;

typedef struct rb_tree {
    Node* root;
    Node* null;
} RBTree;

// Function declarations
RBTree* alloc_tree();
Node* alloc_node(int value, int color, Node* parent, Node* left, Node* right);
void delete_tree(RBTree* tree);
void delete_node(RBTree* tree, Node* z);
Node* search_key(RBTree* tree, int value);
void insert_key(RBTree* tree, int value);

// Internal helper functions (for rotations and rebalancing)
void left_rotation(RBTree* tree, Node* x);
void right_rotation(RBTree* tree, Node* y);
void fix_insertion(RBTree* tree, Node* z);
void fix_delete(RBTree* tree, Node* x);

#endif // RED_BLACK_TREE_H
