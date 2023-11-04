#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    size_t mid;
    avl_t *tree;

    if (!array || !size)
        return (NULL);

    tree = malloc(sizeof(*tree));
    if (!tree)
        return (NULL);

    mid = size / 2;
    tree->n = array[mid];
    tree->parent = NULL;
    tree->left = sorted_array_to_avl(array, mid);
    tree->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
    if (tree->left)
        tree->left->parent = tree;
    if (tree->right)
        tree->right->parent = tree;

    return (tree);
}

/**
 * binary_tree_node - creates a binary tree node
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */
avl_t *binary_tree_node(avl_t *parent, int value)
{
    avl_t *new_node;

    new_node = malloc(sizeof(*new_node));
    if (new_node)
    {
        new_node->n = value;
        new_node->parent = parent;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return (new_node);
}
