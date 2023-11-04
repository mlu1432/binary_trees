#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value into
 * @value: value to store in the node to be inserted
 *
 * Return: If no array is given or the function fails - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * The created node must be a root node if the tree is NULL.
 *
 * Value must be ignored if it is already in the tree.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *node = NULL, *parent = NULL;

    if (tree == NULL)
        return (NULL);

    parent = *tree;
    while (1)
    {
        if (parent == NULL)
        {
            node = binary_tree_node(parent, value);
            if (node == NULL)
                return (NULL);
            if (parent == NULL)
                *tree = node;
            return (node);
        }
        if (parent->n == value)
            return (NULL);
        if (parent->n < value)
        {
            if (parent->right != NULL)
            {
                parent = parent->right;
                continue;
            }
            parent->right = binary_tree_node(parent, value);
            return (parent->right);
        }
        if (parent->n > value)
        {
            if (parent->left != NULL)
            {
                parent = parent->left;
                continue;
            }
            parent->left = binary_tree_node(parent, value);
            return (parent->left);
        }
    }
}
