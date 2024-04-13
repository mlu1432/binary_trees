#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Description: This function takes the right child of the root and makes it
 * the new root of the subtree while setting the old root as its left child.
 * The old root's right child is replaced by the new root's left child.
 * Return: A pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
	{
		return (tree);
	}

	new_root = tree->right;
	tree->right = new_root->left;

	if (new_root->left != NULL)
	{
		new_root->left->parent = tree;
	}

	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
