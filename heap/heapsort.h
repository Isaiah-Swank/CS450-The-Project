#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stddef.h> // For size_t
#include <stdio.h>  // For debugging or general output

/**
 * Function to perform heapsort on an array.
 * @param arr Pointer to the array to be sorted.
 * @param n Size of the array.
 */
void heapsort(int *arr, int n);

/**
 * Helper function to maintain heap property.
 * @param arr Pointer to the array.
 * @param n Size of the heap.
 * @param i Index of the current node.
 */
void heapify(int *arr, int n, int i);

#endif // HEAPSORT_H
