#include <deepstate/DeepState.hpp>
#include "linked_list.h" // Include the header file for the linked list

using namespace deepstate;

TEST(LinkedList, AppendAndGet) {
    linked_list list = make_list();

    const int num_operations = DeepState_IntInRange(1, 100);
    for (int i = 0; i < num_operations; ++i) {
        int value = DeepState_Int();
        append(&list, value);
        ASSERT(get(list, i) == value) << "Get did not return the appended value at index " << i;
    }

    free_list(list);
}

TEST(LinkedList, PushAndPop) {
    linked_list list = make_list();

    const int num_operations = DeepState_IntInRange(1, 100);
    for (int i = 0; i < num_operations; ++i) {
        int value = DeepState_Int();
        push(&list, value);
        ASSERT(get(list, 0) == value) << "Get did not return the pushed value at index 0.";
    }

    for (int i = 0; i < num_operations; ++i) {
        int value = pop(&list);
        ASSERT(list.size == (num_operations - i - 1)) << "Size did not decrease correctly after pop.";
    }

    ASSERT(list.size == 0) << "List is not empty after popping all elements.";

    free_list(list);
}

TEST(LinkedList, SetAndGet) {
    linked_list list = make_list();

    const int num_operations = DeepState_IntInRange(1, 100);
    for (int i = 0; i < num_operations; ++i) {
        append(&list, 0); // Initialize with default values
    }

    for (int i = 0; i < num_operations; ++i) {
        int value = DeepState_Int();
        set(list, i, value);
        ASSERT(get(list, i) == value) << "Set or Get failed at index " << i;
    }

    free_list(list);
}

TEST(LinkedList, PopLast) {
    linked_list list = make_list();

    const int num_operations = DeepState_IntInRange(1, 100);
    for (int i = 0; i < num_operations; ++i) {
        append(&list, i);
    }

    for (int i = num_operations - 1; i >= 0; --i) {
        int value = pop_last(&list);
        ASSERT(value == i) << "PopLast did not return the correct value.";
        ASSERT(list.size == i) << "Size did not decrease correctly after PopLast.";
    }

    ASSERT(list.size == 0) << "List is not empty after popping all elements.";

    free_list(list);
}