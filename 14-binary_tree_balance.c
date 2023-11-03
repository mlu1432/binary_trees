#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l;
    size_t height_r;

    height_l = tree && tree->left ? 1 + binary_tree_height(tree->left) : 0;
    height_r = tree && tree->right ? 1 + binary_tree_height(tree->right) : 0;
    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_balance - Function that measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance factor of a binary tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int balance;

    if (!tree)
    {
        return (0);
    }

    balance = (int)binary_tree_height(tree->left) - (int)binary_tree_height(tree->right);
    return (balance);
}
