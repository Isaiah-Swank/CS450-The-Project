#include <deepstate/DeepState.hpp>
#include "stack.h" // Include the header file for the stack

using namespace deepstate;

TEST(StackArray, PushPop) {
    stack_array stack = { .size = 0 };

    const int num_operations = DeepState_IntInRange(1, STACK_CAP);
    for (int i = 0; i < num_operations; ++i) {
        int elem = DeepState_Int();
        push_stack_array(&stack, elem);
        ASSERT(peek_stack_array(&stack) == elem) << "Peek does not return the last pushed element.";
    }

    for (int i = num_operations - 1; i >= 0; --i) {
        int popped = pop_stack_array(&stack);
        ASSERT(popped == i) << "Pop does not return elements in reverse push order.";
    }

    ASSERT(empty_stack_array(&stack)) << "Stack is not empty after popping all elements.";
}

TEST(StackLinkedList, PushPop) {
    node* stack = NULL;

    const int num_operations = DeepState_IntInRange(1, 100);
    for (int i = 0; i < num_operations; ++i) {
        int elem = DeepState_Int();
        node* new_node = make_list(elem);
        push_stack_nhll(&stack, new_node);
        ASSERT(peek_stack_nhll(&stack) == elem) << "Peek does not return the last pushed element.";
    }

    for (int i = 0; i < num_operations; ++i) {
        node* popped_node = pop_stack_nhll(&stack);
        ASSERT(popped_node->value == i) << "Pop does not return elements in reverse push order.";
        free(popped_node);
    }

    ASSERT(empty_stack_nhll(&stack)) << "Stack is not empty after popping all elements.";
}

TEST(StackHeadLinkedList, PushPop) {
    stack_ll stack = { .size = 0, .head = NULL };

    const int num_operations = DeepState_IntInRange(1, 100);
    for (int i = 0; i < num_operations; ++i) {
        int elem = DeepState_Int();
        push_stack_hll(&stack, elem);
        ASSERT(peek_stack_hll(&stack) == elem) << "Peek does not return the last pushed element.";
    }

    for (int i = 0; i < num_operations; ++i) {
        int popped = pop_stack_hll(&stack);
        ASSERT(popped == i) << "Pop does not return elements in reverse push order.";
    }

    ASSERT(empty_stack_hll(&stack)) << "Stack is not empty after popping all elements.";
}
