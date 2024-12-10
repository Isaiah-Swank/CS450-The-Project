#include <deepstate/DeepState.hpp>
#include "linked-list.h"

using namespace deepstate;

TEST(LinkedList, BasicOperations) {
    Node* head = NULL;
    int size = DeepState_IntInRange(1, 100);

    for (int i = 0; i < size; i++) {
        int value = DeepState_Int();
        head = insertNode(head, value);
        ASSERT(findNode(head, value) != NULL);
    }

    int target = DeepState_Int();
    Node* result = findNode(head, target);

    if (result != NULL) {
        ASSERT(result->data == target);
    } else {
        LOG(TRACE) << "Node with data " << target << " not found.";
    }

    freeList(head);
}
