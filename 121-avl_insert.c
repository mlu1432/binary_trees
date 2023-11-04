#include "binary_trees.h"

int binary_tree_balance(const binary_tree_t *tree);

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: a pointer to the root node of the tree to rotate.
 *
 * Return: a pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *pivot, *temp;

    if (tree == NULL)
        return (NULL);

    pivot = tree->left;
    temp = pivot->right;
    pivot->right = tree;
    tree->left = temp;

    if (tree->parent)
    {
        if (tree->parent->left == tree)
            tree->parent->left = pivot;
        else
            tree->parent->right = pivot;
    }

    pivot->parent = tree->parent;
    tree->parent = pivot;
    return (pivot);
}

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: a pointer to the root node of the tree to rotate.
 *
 * Return: the new root after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *pivot, *temp;

    if (tree == NULL)
        return (NULL);

    pivot = tree->right;
    temp = pivot->left;
    pivot->left = tree;
    tree->right = temp;

    if (tree->parent)
    {
        if (tree->parent->right == tree)
            tree->parent->right = pivot;
        else
            tree->parent->left = pivot;
    }

    pivot->parent = tree->parent;
    tree->parent = pivot;
    return (pivot);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: a double pointer to the root node of the AVL Tree to insert the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node, *temp_node;
    int balance;

    if (tree == NULL)
        return (NULL);
    else if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }
    else if (value > (*tree)->n)
    {
        new_node = avl_insert(&((*tree)->right), value);
        if ((*tree)->right == NULL)
            (*tree)->right = new_node;
    }
    else if (value < (*tree)->n)
    {
        new_node = avl_insert(&((*tree)->left), value);
        if ((*tree)->left == NULL)
            (*tree)->left = new_node;
    }
    else
        return (NULL);

    balance = binary_tree_balance(*tree);

    if (balance > 1 && value < (*tree)->left->n)
        return (binary_tree_rotate_right(*tree));
    if (balance < -1 && value > (*tree)->right->n)
        return (binary_tree_rotate_left(*tree));
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return (binary_tree_rotate_right(*tree));
    }
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return (binary_tree_rotate_left(*tree));
    }
    if (*tree == NULL)
        *tree = new_node;
    return (*tree);
}
