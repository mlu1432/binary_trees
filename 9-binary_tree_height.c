#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Description:
 * This function calculates the height of a binary tree. The height is defined
 * as the length of the longest path from the root node to a leaf node. If the
 * tree is NULL, the function returns 0.
 *
 * Return: The height of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        size_t left_height = 0;
        size_t right_height = 0;

        left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
        right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
        
        return (left_height > right_height ? left_height : right_height);
    }
    else
    {
        return 0;
    }
}
