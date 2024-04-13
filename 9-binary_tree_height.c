#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree starting at @tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL)
	{
		return (0);
	}

	/* Calculate the height of the left subtree, if it exists */
	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;

	/* Calculate the height of the right subtree, if it exists */
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* Return the greater of the two heights */
	return (height_left > height_right ? height_left : height_right);
}
