#include "binary_trees.h"

/**
 * binary_tree_nodes - Function that counts the nodes with at least 1 child in a binary tree.
 * @tree: This is a pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, your function must return 0. Otherwise, it should return node_count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t node_count = 0;

    if (tree)
    {
        node_count += (tree->left || tree->right) ? 1 : 0;
        node_count += binary_tree_nodes(tree->left);
        node_count += binary_tree_nodes(tree->right);
    }
    return (node_count);
}
