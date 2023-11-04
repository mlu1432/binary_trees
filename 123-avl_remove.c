#include "binary_trees.h"
#include <stdlib.h>

avl_t *binary_tree_inorder_successor(avl_t *node);
avl_t *delete_and_rebalance(avl_t *root, avl_t *node_to_delete);

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the desired value,
 * and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
        return delete_and_rebalance(root, root);

    return root;
}

/**
 * binary_tree_inorder_successor - Returns the in-order successor of a node in a binary tree
 * @node: Pointer to the node
 *
 * Return: Pointer to the in-order successor node
 */
avl_t *binary_tree_inorder_successor(avl_t *node)
{
    avl_t *current = node;

    /* Loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/**
 * delete_and_rebalance - Deletes a node and rebalances an AVL tree
 * @root: Pointer to the root node of the tree
 * @node_to_delete: Pointer to the node to delete
 *
 * Return: Pointer to the new root node of the tree after deleting the node and rebalancing
 */
avl_t *delete_and_rebalance(avl_t *root, avl_t *node_to_delete)
{
    if (node_to_delete->left == NULL)
    {
        avl_t *temp = node_to_delete->right;
        free(node_to_delete);
        return temp;
    }
    else if (node_to_delete->right == NULL)
    {
        avl_t *temp = node_to_delete->left;
        free(node_to_delete);
        return temp;
    }

    // Node with two children: Get the inorder successor
    avl_t *temp = binary_tree_inorder_successor(node_to_delete->right);

    // Copy the inorder successor's content to the node
    node_to_delete->n = temp->n;

    // Delete the inorder successor
    node_to_delete->right = avl_remove(node_to_delete->right, temp->n);

    return root;
}
