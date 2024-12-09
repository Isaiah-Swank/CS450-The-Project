#ifndef MERGESORT_H
#define MERGESORT_H

#include <stddef.h> // For size_t
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);

#endif
