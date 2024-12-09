#include <algorithm>
#include <deepstate/DeepState.hpp>
#include "red_black_tree.h" // Update as needed if header files are different.

using namespace deepstate;

TEST(RedBlackTree, BasicProperties) {
    RBTree* tree = alloc_tree();

    // Generate a random sequence of integers to insert.
    const int size = DeepState_IntInRange(1, 100);
    std::vector<int> values;

    for (int i = 0; i < size; ++i) {
        int value = DeepState_Int();
        values.push_back(value);
        insert_key(tree, value);

        // Validate Red-Black Tree properties.
        ASSERT(tree->root->color == B) << "Root must be black.";
        ASSERT(validate_rb_tree(tree, tree->root)) << "Tree properties violated.";
    }

    // Shuffle and delete half the elements randomly.
    std::shuffle(values.begin(), values.end(), std::mt19937{std::random_device{}()});
    for (int i = 0; i < size / 2; ++i) {
        Node* to_delete = search_key(tree, values[i]);
        if (to_delete != tree->null) {
            delete_node(tree, to_delete);

            // Validate Red-Black Tree properties.
            ASSERT(tree->root->color == B) << "Root must be black after deletion.";
            ASSERT(validate_rb_tree(tree, tree->root)) << "Tree properties violated after deletion.";
        }
    }

    delete_tree(tree);
}

bool validate_rb_tree(RBTree* tree, Node* node) {
    if (node == tree->null) return true;

    // Property 1: Root is black.
    if (node == tree->root && node->color != B) {
        return false;
    }

    // Property 2: Red nodes cannot have red children.
    if (node->color == R) {
        if (node->left->color == R || node->right->color == R) {
            return false;
        }
    }

    // Property 3: Every path from a node to its descendant null nodes contains the same number of black nodes.
    int left_black_height = black_height(tree, node->left);
    int right_black_height = black_height(tree, node->right);
    if (left_black_height != right_black_height) {
        return false;
    }

    // Recursively check the subtrees.
    return validate_rb_tree(tree, node->left) && validate_rb_tree(tree, node->right);
}

int black_height(RBTree* tree, Node* node) {
    if (node == tree->null) return 1;

    int left_height = black_height(tree, node->left);
    int right_height = black_height(tree, node->right);
    ASSERT(left_height == right_height) << "Inconsistent black height detected.";

    return left_height + (node->color == B ? 1 : 0);
}
