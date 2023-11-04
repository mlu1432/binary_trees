#include "binary_trees.h"

/**
 * Leftmost Node at the last level
 * @root: pointer to the root node
 * @height: height of the heap
 *
 * Return: Pointer to the leftmost Node at the last level
 */
heap_t *last_level(heap_t **root, int height)
{
    heap_t *node = *root;

    if (height == 0)
        return (node);
    if (binary_tree_height(node->left) == height - 1)
    {
        if (node->left != NULL)
            return (last_level(&(node->left), height - 1));
        else
            return (last_level(&(node->right), height - 1));
    }
    return (node);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: is a double pointer to the root node
 *
 * Return: the value stored in the root node
 */
int heap_extract(heap_t **root)
{
    int value, temp_value;
    heap_t *node, *last_node;
    size_t height;

    if (root == NULL || *root == NULL)
        return (0);
    node = *root;
    value = node->n;

    if (!node->left && !node->right)
    {
        free(node);
        *root = NULL;
        return (value);
    }

    height = binary_tree_height(node);
    last_node = last_level(root, height);
    if (last_node->parent->right)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;

    temp_value = node->n;
    node->n = last_node->n;
    last_node->n = temp_value;

    free(last_node);

    heapify_down(root);

    return (value);
}
