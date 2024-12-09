#include <algorithm>
#include <deepstate/DeepState.hpp>
#include "selection_sort.h"

using namespace deepstate;

#define MAX_SIZE 20

TEST(SelectionSort, Basic) {
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

    // Apply the selection sort algorithm
    selection_sort(arr, size);

    // Log the sorted array
    LOG(TRACE) << "Sorted array:";
    for (int i = 0; i < size; i++) {
        LOG(TRACE) << "arr[" << i << "] = " << arr[i];
    }

    // Validate the selection sort output
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], sorted_arr[i]) << "Mismatch at index " << i;
    }
}

TEST(SelectionSort, EdgeCases) {
    int arr[MAX_SIZE] = {0};

    // Test with empty array
    selection_sort(arr, 0);
    ASSERT_TRUE(true) << "Empty array handled correctly.";

    // Test with single element array
    arr[0] = DeepState_Int();
    selection_sort(arr, 1);
    ASSERT_TRUE(true) << "Single element array handled correctly.";

    // Test with all identical elements
    int val = DeepState_Int();
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = val;
    }
    selection_sort(arr, MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        ASSERT_EQ(arr[i], val) << "Mismatch in array with identical elements.";
    }
}