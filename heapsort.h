#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stddef.h> // For size_t
#include <stdio.h>

void heap_sort(int* arr, size_t arr_len);
void heapify(int *arr, int n, int i);

#endif