#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least one child in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of nodes
 *
 * Description: This function recursively counts the nodes in a binary tree
 * that have at least one child, which are not leaf nodes.
 * Return: The number of nodes with at least one child, or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* Check if the tree pointer is NULL, indicating no nodes */
	if (tree == NULL)
	{
		return (0);
	}

	/* Check if the current node has at least one child */
	if (tree->left != NULL || tree->right != NULL)
	{
	/* Count this node and recurse on both children */
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	}

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
