#include "binary_trees.h"

/**
 * heapify_up - Adjusts the heap by moving a node up
 * @tree: Pointer to the node to heapify up
 * Return: yoooii
 */
void heapify_up(heap_t **tree)
{
    heap_t *temp = *tree;
    int value;

    while (temp->parent && temp->n > temp->parent->n)
    {
        value = temp->parent->n;
        temp->parent->n = temp->n;
        temp->n = value;
        temp = temp->parent;
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *temp;
    
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    temp = *root;
    while (temp->left && temp->right)
    {
        if (binary_tree_is_complete(temp->left) && binary_tree_is_complete(temp->right))
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (!temp->left)
        temp->left = new_node;
    else
        temp->right = new_node;

    new_node->parent = temp;
    heapify_up(&new_node);

    return (new_node);
}
