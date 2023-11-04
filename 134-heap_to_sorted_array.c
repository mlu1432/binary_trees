#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 * 
 * Return: a sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array;
    size_t i = 0;

    if (!heap || !size)
        return (NULL);

    *size = binary_tree_nodes(heap);
    
    sorted_array = malloc(sizeof(int) * (*size));
    if (!sorted_array)
        return (NULL);
    
    while (heap)
    {
        sorted_array[i] = heap_extract(&heap);
        i++;
    }
    
    return (sorted_array);
}
