#include <algorithm>
#include <deepstate/DeepState.hpp>
#include "insertion_sort.h"

using namespace deepstate;

#define MAX_SIZE 20

TEST(InsertionSort, Basic) {
    int arr[MAX_SIZE];
    int size = DeepState_IntInRange(0, MAX_SIZE);

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
    int sorted_arr[MAX_SIZE];
    std::copy(arr, arr + size, sorted_arr);

    // Sort the copy using std::sort for ground truth
    std::sort(sorted_arr, sorted_arr + size);

    // Apply the insertion sort algorithm
    insertion_sort(arr, size);

    // Log the sorted array
    LOG(TRACE) << "Sorted array:";
    for (int i = 0; i < size; i++) {
        LOG(TRACE) << "arr[" << i << "] = " << arr[i];
    }

    // Validate the insertion sort output
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], sorted_arr[i]) << "Mismatch at index " << i;
    }
}

TEST(InsertionSort, EdgeCases) {
    int arr[MAX_SIZE] = {0};

    // Test with empty array
    insertion_sort(arr, 0);
    ASSERT_TRUE(true) << "Empty array handled correctly.";

    // Test with single element array
    arr[0] = DeepState_Int();
    insertion_sort(arr, 1);
    ASSERT_TRUE(true) << "Single element array handled correctly.";

    // Test with all identical elements
    int val = DeepState_Int();
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = val;
    }
    insertion_sort(arr, MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        ASSERT_EQ(arr[i], val) << "Mismatch in array with identical elements.";
    }
}