#include "binary_trees.h"
#include <stdlib.h>
#include <stdbool.h>

bool is_fifo_empty(queue_t *head);
void fifo_push(queue_t **head, struct binary_tree_s *node);
struct binary_tree_s *fifo_pop(queue_t **head);

/**
 * fifo_pop - removes an item from the front of a 'queue'
 *
 * @head: pointer to queue
 * Return: void
 **/
struct binary_tree_s *fifo_pop(queue_t **head)
{
    struct binary_tree_s *node;
    queue_t *temp;

    node = (*head)->node;
    temp = (*head);
    (*head) = (*head)->next;
    free(temp);
    return (node);
}

/**
 * is_fifo_empty - checks if queue is empty
 * @head: pointer to queue
 *
 * Return: true if empty, false otherwise
 **/
bool is_fifo_empty(queue_t *head)
{
    if (head == NULL)
        return (true);
    return (false);
}

/**
 * fifo_push - adds a new item to the end of the FIFO queue
 * @head: pointer to the head of the FIFO queue
 * @node: pointer to the node to add to the queue
 * Return: void
 **/
void fifo_push(queue_t **head, struct binary_tree_s *node)
{
    queue_t *newNode, *temp;

    newNode = malloc(sizeof(queue_t));
    if (newNode == NULL)
        /* Handle memory allocation failure */
        return;

    newNode->node = node;
    newNode->next = NULL;

    if (is_fifo_empty(*head))
    {
        *head = newNode;
        return;
    }

    temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if tree is complete, 0 otherwise
 **/
int binary_tree_is_complete(const binary_tree_t *tree)
{
    queue_t *queue;
    int isComplete = 0;
    struct binary_tree_s *temp;

    if (tree == NULL)
        return (0);

    queue = NULL;
    fifo_push(&queue, (struct binary_tree_s *)tree);
    while (queue != NULL)
    {
        temp = fifo_pop(&queue);
        if (temp->left)
        {
            if (isComplete == 1)
                return (0);
            fifo_push(&queue, temp->left);
        }
        else
            isComplete = 1;

        if (temp->right)
        {
            if (isComplete == 1)
                return (0);
            fifo_push(&queue, temp->right);
        }
        else
            isComplete = 1;
    }

    return (1);
}
