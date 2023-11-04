#include "binary_trees.h"
#include <stdbool.h>
#include <limits.h>

/**
 * is_bst_helper - Recursive helper function to check if a binary tree is a BST.
 * @tree: Pointer to the current node.
 * @min: Minimum allowed value for the current node.
 * @max: Maximum allowed value for the current node.
 *
 * Return: true if the tree is a valid BST, false otherwise.
 */
bool is_bst_helper(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return true;

    if (tree->n <= min || tree->n >= max)
        return false;

    return is_bst_helper(tree->left, min, tree->n) &&
           is_bst_helper(tree->right, tree->n, max);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree (BST).
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return is_bst_helper(tree, INT_MIN, INT_MAX);
}
