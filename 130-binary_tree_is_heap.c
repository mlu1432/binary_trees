#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * return: size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (binary_tree_size(tree->left) +
            binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t idx, size;

    if (!tree)
        return (0);
    size = binary_tree_size(tree);
    return (binary_tree_is_complete_helper(tree, &idx, 0, size));
}

/**
 * prop_max_heap - checks for the max heap property in a heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int prop_max_heap(const binary_tree_t *tree)
{
    if (!tree->left)
    {
        if (!tree->right)
            return (1);
        else
            return (0);
    }
    if (tree->n >= tree->left->n && (!tree->right || tree->n >= tree->right->n))
        return (prop_max_heap(tree->left) && prop_max_heap(tree->right));
    else
        return (0);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    if (binary_tree_is_complete(tree) && prop_max_heap(tree))
        return (1);
    return (0);
}
