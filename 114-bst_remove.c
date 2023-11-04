#include "binary_trees.h"

bst_t *find_successor(bst_t *node);
bst_t *bst_remove(bst_t *root, int value);

/**
 * find_successor - Finds the in-order successor of a node.
 * @node: The node for which to find the successor.
 *
 * Return: A pointer to the in-order successor node.
 */
bst_t *find_successor(bst_t *node)
{
    bst_t *current = node->right;

    while (current && current->left)
        current = current->left;

    return current;
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: A pointer to the root node of the BST.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else {
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        bst_t *temp = find_successor(root);
        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}
