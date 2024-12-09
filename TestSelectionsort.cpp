#include <algorithm>
#include <deepstate/DeepState.hpp>
using namespace deepstate;

#include "selection_sort.h"

#define MAX_SIZE 20

TEST(SelectionSort, Basic) {
    int arr[MAX_SIZE];
    size_t size = DeepState_SizeInRange(0, MAX_SIZE);

    for (size_t i = 0; i < size; i++) {
        arr[i] = DeepState_Int();
    }

    LOG(TRACE) << "Original array:";
    for (size_t i = 0; i < size; i++) {
        LOG(TRACE) << "arr[" << i << "] = " << arr[i];
    }

    selection_sort(arr, size);

    LOG(TRACE) << "Sorted array:";
    for (size_t i = 0; i < size; i++) {
        LOG(TRACE) << "arr[" << i << "] = " << arr[i];
    }

    // Verify the array is sorted
    for (size_t i = 1; i < size; i++) {
        ASSERT_LE(arr[i - 1], arr[i]) << "Array is not sorted correctly.";
    }
}
