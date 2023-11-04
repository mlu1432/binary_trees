#include "binary_trees.h"

int height(const binary_tree_t *tree);
int is_balanced(const binary_tree_t *tree);
int bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the Tree to check.
 *
 * Return: If the tree is a valid AVL tree, return 1, else, 0.
 *         If tree is NULL, return 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (is_balanced(tree) && bst(tree, INT_MIN, INT_MAX));
}

/**
 * is_balanced - Checks if a binary tree is balanced.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is balanced, return 1, else, 0.
 */
int is_balanced(const binary_tree_t *tree)
{
    int left_h;
    int right_h;

    if (!tree)
        return (1);

    left_h = height(tree->left);
    right_h = height(tree->right);

    return (abs(left_h - right_h) < 2 &&
            is_balanced(tree->left) &&
            is_balanced(tree->right));
}

/**
 * height - Measures the height of a tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, return 0, else, return height.
 */
int height(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (MAX(height(tree->left), height(tree->right)) + 1);
}

/**
 * bst - Checks if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The value of the smallest node visited so far.
 * @max: The value of the largest node visited so far.
 *
 * Return: If the tree is a valid BST, return 1, else, 0.
 */
int bst(const binary_tree_t *tree, int min, int max)
{
    if (!tree)
        return (1);

    if (tree->n < min || tree->n > max)
        return (0);

    return (bst(tree->left, min, tree->n - 1) &&
            bst(tree->right, tree->n + 1, max));
}
