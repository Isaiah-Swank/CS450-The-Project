#include <deepstate/DeepState.hpp>
#include "dynamic_array.h" // Include the header file for the dynamic array

using namespace deepstate;

TEST(DynamicArray, AddAndGet) {
    dyn_array arr = make_array(1);

    const int num_operations = DeepState_IntInRange(1, 100);
    for (int i = 0; i < num_operations; ++i) {
        int value = DeepState_Int();
        add(&arr, value);
        ASSERT(get(arr, i) == value) << "Get did not return the added value at index " << i;
    }

    free_array(arr);
}

TEST(DynamicArray, InsertAndDelete) {
    dyn_array arr = make_array(1);

    const int num_operations = DeepState_IntInRange(1, 100);
    for (int i = 0; i < num_operations; ++i) {
        add(&arr, i);
    }

    const int insert_index = DeepState_IntInRange(0, num_operations - 1);
    const int insert_value = DeepState_Int();
    insert(&arr, insert_index, insert_value);
    ASSERT(get(arr, insert_index) == insert_value) << "Insert failed at index " << insert_index;

    const int delete_index = DeepState_IntInRange(0, arr.size - 1);
    int deleted_value = delete(&arr, delete_index);
    ASSERT(deleted_value == get(arr, delete_index)) << "Delete did not return the correct value.";

    free_array(arr);
}

TEST(DynamicArray, Pop) {
    dyn_array arr = make_array(1);

    const int num_operations = DeepState_IntInRange(1, 100);
    for (int i = 0; i < num_operations; ++i) {
        add(&arr, i);
    }

    for (int i = num_operations - 1; i >= 0; --i) {
        int popped_value = pop(&arr);
        ASSERT(popped_value == i) << "Pop did not return the correct value.";
    }

    ASSERT(arr.size == 0) << "Array is not empty after popping all elements.";

    free_array(arr);
}

TEST(DynamicArray, Resize) {
    dyn_array arr = make_array(1);

    const int num_operations = DeepState_IntInRange(1, 100);
    for (int i = 0; i < num_operations; ++i) {
        add(&arr, i);
        ASSERT(arr.cap >= arr.size) << "Capacity is less than size after adding elements.";
    }

    for (int i = 0; i < num_operations; ++i) {
        pop(&arr);
        ASSERT(arr.cap >= arr.size) << "Capacity is less than size after popping elements.";
    }

    free_array(arr);
}