#include "mergesort.h"

void merge(int *arr, int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    int temp[end - start + 1];

    // Merge the two subarrays into temp
    while (i <= mid && j <= end) {
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }

    // Copy any remaining elements from the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy any remaining elements from the right subarray
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // Copy temp back into the original array
    for (k = 0, i = start; i <= end; ++i, ++k) {
        arr[i] = temp[k];
    }
}

void merge_sort(int *arr, int start, int end) {
    if (start >= end) {
        return; // Base case: single element or invalid range
    }

    int mid = start + (end - start) / 2;

    // Recursive calls for each half
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    // Merge sorted halves
    merge(arr, start, mid, end);
}
