#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Standard Libraries */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Binary Tree Node Structure */
typedef struct binary_tree_s {
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/*Queue struct used for storing nodes during BFS traversal*/
typedef struct queue
{
    struct binary_tree_s *node;
    struct queue *next;
} queue_t;

/* Binary Search Tree (BST), AVL Tree, and Heap Types */
typedef binary_tree_t bst_t;
typedef binary_tree_t avl_t;
typedef binary_tree_t heap_t;

/* Queue Structure for Level Order Traversal */
typedef struct levelorder_queue_s {
    binary_tree_t *node;
    struct levelorder_queue_s *next;
} levelorder_queue_t;

/* Function Prototypes for Binary Tree Operations */

/* Basic Binary Tree Functions */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);

/* Properties and Characteristics */
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
heap_t *last_level(heap_t **root, int height);
int heap_extract(heap_t **root);

/* Tree Traversal Functions */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Binary Search Tree (BST) Operations */
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);

/* AVL Tree Operations */
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);

/* Max Binary Heap Operations */
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
heap_t *swap(heap_t **node);
heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_size(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int prop_max_heap(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
