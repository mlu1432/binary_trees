#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Returns: a pointer to the lowest common ancestor node of the two given nodes
 * or NULL if no common ancestor was found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    binary_tree_t *temp;

    if (first == NULL || second == NULL)
        return (NULL);
    
    while (first)
    {
        temp = (binary_tree_t *)second;
        while (temp)
        {
            if (first == temp)
                return ((binary_tree_t *)first);
            temp = temp->parent;
        }
        first = first->parent;
    }
    return (NULL);
}
