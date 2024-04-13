#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	const binary_tree_t **queue = malloc(sizeof(*queue) * 1024);

	if (!queue)
		return (0);

	int front = 0, rear = 0;
	int non_full_node_found = 0;

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		if (!current->left || !current->right)
		{
			if (non_full_node_found)
			{
				free(queue);
				return (0);
			}
			non_full_node_found = 1;
		}

		if (current->left)
		queue[rear++] = current->left;
		if (current->right)
		queue[rear++] = current->right;
		else
		break;
	}

	free(queue);
	return (1);
}
