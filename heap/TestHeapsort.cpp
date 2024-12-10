#include <algorithm>
#include <deepstate/DeepState.hpp>
#include "heapsort.h"

using namespace deepstate;

#define MAX_SIZE 20

TEST(Heapsort, BasicOperations) {
    int size = DeepState_IntInRange(1, MAX_SIZE);
    int* arr = (int*)malloc(size * sizeof(int));

    // Populate the array with random integers
    for (int i = 0; i < size; i++) {
        arr[i] = DeepState_Int();
    }

    // Log the initial array
    LOG(TRACE) << "Original array:";
    for (int i = 0; i < size; i++) {
        LOG(TRACE) << "arr[" << i << "] = " << arr[i];
    }

    // Create a copy of the array for validation
    int* sorted_arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        sorted_arr[i] = arr[i];
    }

    // Sort the copy using std::sort for ground truth
    std::sort(sorted_arr, sorted_arr + size);

    // Apply the heapsort algorithm
    heapsort(arr, size);

    // Log the sorted array
    LOG(TRACE) << "Sorted array:";
    for (int i = 0; i < size; i++) {
        LOG(TRACE) << "arr[" << i << "] = " << arr[i];
    }

    // Validate the heapsort output
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], sorted_arr[i]) << "Mismatch at index " << i;
    }

    free(arr);
    free(sorted_arr);
}

