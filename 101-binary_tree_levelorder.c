#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t height, level;

    if (tree == NULL || func == NULL)
        return;

    height = binary_tree_height(tree);

    for (level = 1; level <= height + 1; level++)
        binary_tree_print_level(tree, func, level);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, or 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_print_level - Prints a binary tree level.
 * @tree: A pointer to the root node of the tree to print.
 * @func: A pointer to a function to call for each node.
 * @level: The level to print.
 */
void binary_tree_print_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
    if (tree == NULL)
        return;

    if (level == 1)
        func(tree->n);
    else if (level > 1)
    {
        binary_tree_print_level(tree->left, func, level - 1);
        binary_tree_print_level(tree->right, func, level - 1);
    }
}
