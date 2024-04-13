#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of leaves
 *
 * Description: This function recursively counts the leaves of a binary tree,
 * a leaf being a node with no children.
 * Return: The number of leaf nodes in the tree, or 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* Handle NULL case first */
	if (tree == NULL)
	{
		return (0);
	}

	/* Check if the node is a leaf */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	/* Recursively count leaves in both subtrees and return the sum */
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
