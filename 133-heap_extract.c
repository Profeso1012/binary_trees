#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *temp;
	size_t size, i, index;
	
	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	size = binary_tree_size(*root);
	last_node = *root;

	/* Find the last level-order node */
	for (i = 0; i < size - 1; i++)
		last_node = last_node->left;

	/* Swap root node with last node */
	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	(*root)->n = last_node->n;
	temp = last_node->parent;
	if (temp->right)
		temp->right = NULL;
	else
		temp->left = NULL;
	free(last_node);

	/* Rebuild heap */
	temp = *root;
	while (temp)
	{
		heapify_down(temp);
		if (temp->left && temp->left->n > temp->n)
			temp = temp->left;
		else if (temp->right && temp->right->n > temp->n)
			temp = temp->right;
		else
			break;
	}

	return (value);
}
