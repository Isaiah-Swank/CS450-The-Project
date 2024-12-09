#include <algorithm>
#include <deepstate/DeepState.hpp>
using namespace deepstate;

#include <cstring>  // For memcpy

#define MAX_SIZE 20

extern "C" {
    void merge_sort(int* arr, size_t start, size_t end, int* target);
}

TEST(MergeSort, Basic) {
    int arr[MAX_SIZE];
    int target[MAX_SIZE];
    size_t size = DeepState_SizeTInRange(0, MAX_SIZE);

    for (size_t i = 0; i < size; i++) {
        arr[i] = DeepState_Int();
    }

    LOG(TRACE) << "Original array:";
    for (size_t i = 0; i < size; i++) {
        LOG(TRACE) << "arr[" << i << "] = " << arr[i];
    }

    merge_sort(arr, 0, size, target);

    LOG(TRACE) << "Sorted array:";
    for (size_t i = 0; i < size; i++) {
        LOG(TRACE) << "arr[" << i << "] = " << arr[i];
    }

    // Verify the array is sorted
    for (size_t i = 1; i < size; i++) {
        ASSERT_LE(arr[i - 1], arr[i]) << "Array is not sorted correctly.";
    }
}
