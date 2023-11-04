#include "binary_trees.h"

/**
 * swap - Swaps current node and parent if current node is greater
 * @node: The heap node to swap
 *
 * Return: The new node as a result of swapping
 */
heap_t *swap(heap_t **node)
{
    heap_t *new_node = *node, *parent = (*node)->parent;

    while (new_node->parent && new_node->n > parent->n)
    {
        if (parent->left == new_node)
        {
            parent->left = new_node->left;
            if (new_node->left)
                new_node->left->parent = parent;
            new_node->left = parent;
            if (parent->parent)
            {
                if (parent->parent->left == parent)
                    parent->parent->left = new_node;
                if (parent->parent->right == parent)
                    parent->parent->right = new_node;
            }
            new_node->parent = parent->parent;
            parent->parent = new_node;
            parent->right = new_node->right;
            if (new_node->right)
                new_node->right->parent = parent;
            new_node->right = parent;
        }
        else if (parent->right == new_node)
        {
            parent->right = new_node->right;
            if (new_node->right)
                new_node->right->parent = parent;
            new_node->right = parent;
            if (parent->parent)
            {
                if (parent->parent->left == parent)
                    parent->parent->left = new_node;
                else
                    parent->parent->right = new_node;
            }
            new_node->parent = parent->parent;
            parent->parent = new_node;
            parent->left = new_node->left;
            if (new_node->left)
                new_node->left->parent = parent;
            new_node->left = parent;
        }
        parent = new_node->parent;
        new_node->parent = new_node->parent ? new_node->parent->parent : NULL;
    }
    return (new_node);
}

/**
 * heap_insert - Inserts a value into a max binary heap
 * @root: Double pointer to the root of the max binary heap
 * @value: The value to insert
 * 
 * Return: Pointer to the newly inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = NULL;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    new_node = *root;
    while (new_node)
    {
        if (!new_node->left)
        {
            new_node->left = binary_tree_node(new_node, value);
            return (swap(&new_node->left));
        }
        else if (!new_node->right)
        {
            new_node->right = binary_tree_node(new_node, value);
            return (swap(&new_node->right));
        }
        else if (binary_tree_is_perfect(new_node->left))
            new_node = new_node->right;
        else
            new_node = new_node->left;
    }
    return (NULL);
}
