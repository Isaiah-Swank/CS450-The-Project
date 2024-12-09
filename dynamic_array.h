#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>

// Dynamic array structure
typedef struct {
    int *data;
    size_t size;
    size_t cap;
} dyn_array;

// Function declarations
dyn_array make_array(size_t init_cap);
void free_array(dyn_array arr);
int get(dyn_array arr, size_t index);
void set(dyn_array *arr, size_t index, int value);
void add(dyn_array *arr, int value);
void insert(dyn_array *arr, size_t index, int value);
int pop(dyn_array *arr);
int delete(dyn_array *arr, size_t index);
void print_arr(dyn_array arr);

#endif // DYNAMIC_ARRAY_H