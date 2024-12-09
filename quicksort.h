#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stddef.h> // For size_t
#include <stdio.h>

void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);

#endif