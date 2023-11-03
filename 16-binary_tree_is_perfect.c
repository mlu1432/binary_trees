#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - A function to identify if a node is a leaf node in a binary tree.
 * If the node is a leaf, function will return 1, else 0.
 * @node: The node to check.
 *
 * Return: unsigned char representing if the node is a leaf or not.
 */
unsigned char is_leaf(const binary_tree_t *node) 
{
    return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - A function to calculate the depth of a particular node in a binary tree.
 * Returns the depth of the input node.
 * @tree: The tree to calculate the depth from.
 *
 * Return: size_t representing the depth of the tree.
 */
size_t depth(const binary_tree_t *tree) 
{
    return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - A function to find and return a leaf node from a binary tree.
 * Returns the first encountered leaf node.
 * @tree: The tree to get the leaf from.
 *
 * Return: binary_tree_t const pointer to the leaf node.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree) 
{
    if (is_leaf(tree) == 1)
        return (tree);
    return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - A function that checks if a binary tree is perfect
 * using a recursive approach.
 * If the tree is perfect then it will return 1, else 0.
 * @tree: The tree to check.
 * @leaf_depth: The depth of the leaf node.
 * @level: The current level.
 *
 * Return: Int flag indicating whether the tree is perfect.
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth, size_t level) 
{
    if (is_leaf(tree))
        return (level == leaf_depth ? 1 : 0);
    if (tree->left == NULL || tree->right == NULL)
        return (0);
    return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
            is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - A function to check if a binary tree is perfect.
 * Returns 0 if the tree is NULL or not perfect, else it will return 1.
 * @tree: The tree to check.
 *
 * Return: Int flag indicating whether the tree is perfect.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
