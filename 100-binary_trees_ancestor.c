#include "binary_trees.h"
#include <stdlib.h>

/**
 * go_up_and_check - Helper function to trace up from node to root
 * and check against a visited array
 * @node: Pointer to the starting node
 * @visited: Array to check for visited nodes
 *
 * Return: Pointer to first common ancestor, or NULL if none found
 */
static binary_tree_t *go_up_and_check(const binary_tree_t *node, int *visited)
{
	while (node != NULL)
	{
		if (visited[node->n])
		{
			return ((binary_tree_t *)node);
		}
		node = node->parent;
	}
	return (NULL);
}
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int visited[1024] = {0};

	if (!first || !second)
	{
		return (NULL);
	}

	const binary_tree_t *temp = first;

	while (temp)
	{
		visited[temp->n] = 1;
		temp = temp->parent;
	}

	return (go_up_and_check(second, visited));
}
