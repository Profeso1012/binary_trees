#include "binary_trees.h"

/**
 * heapify_down - Adjusts the heap by moving a node down
 * @tree: Pointer to the node to heapify down
 *
 * Return: yooo
 */
void heapify_down(heap_t *tree)
{
	heap_t *max, *temp;
	int value;

	max = tree;
	if (tree->left && tree->left->n > max->n)
		max = tree->left;
	if (tree->right && tree->right->n > max->n)
		max = tree->right;

	if (max != tree)
	{
		value = tree->n;
		tree->n = max->n;
		max->n = value;
		heapify_down(max);
	}
}

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created Binary Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t **heap_array;
	size_t i;
	heap_t *root = NULL;

	if (!array || size == 0)
		return (NULL);

	heap_array = malloc(sizeof(heap_t *) * size);
	if (!heap_array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		heap_array[i] = binary_tree_node(NULL, array[i]);
		if (!heap_array[i])
		{
			for (i = 0; i < size; i++)
				free(heap_array[i]);
			free(heap_array);
			return (NULL);
		}
	}

	root = heap_array[0];
	for (i = 0; i < size; i++)
	{
		if (2 * i + 1 < size)
			heap_array[i]->left = heap_array[2 * i + 1];
		if (2 * i + 2 < size)
			heap_array[i]->right = heap_array[2 * i + 2];
	}

	for (i = (size - 1) / 2; (int)i >= 0; i--)
		heapify_down(heap_array[i]);

	free(heap_array);
	return (root);
}
