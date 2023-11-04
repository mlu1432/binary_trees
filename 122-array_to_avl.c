#include "binary_trees.h"
#include <stdlib.h>

avl_t *avl_insert(avl_t **tree, int value);
void avl_delete_tree(avl_t *tree);

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;
    size_t i;

    if (array == NULL || size == 0)
        return NULL;

    for (i = 0; i < size; i++)
    {
        if (avl_insert(&root, array[i]) == NULL)
        {
            /* If insertion fails, free the previously created nodes and return NULL */
            avl_delete_tree(root);
            return NULL;
        }
    }

    return root;
}
