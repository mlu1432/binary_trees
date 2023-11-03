#include "binary_trees.h"

/**
 * binary_tree_leaves - Function that measures how many leaves are in a binary tree.
 * @tree: This is a pointer pointing to the tree's root node which serves as the starting point to tally leaves.
 *
 * Return: This function returns the total count of leaves in the specific tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t leaves = 0;

    if (tree)
    {
        leaves += (!tree->left && !tree->right) ? 1 : 0;
        leaves += binary_tree_leaves(tree->left);
        leaves += binary_tree_leaves(tree->right);
    }
    return (leaves);
}
