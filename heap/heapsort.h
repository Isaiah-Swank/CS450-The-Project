#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stddef.h> // For size_t
#include <stdio.h>

void heapsort(int *arr, int n);
void heapify(int *arr, int n, int i);

#endif // HEAPSORT_H
