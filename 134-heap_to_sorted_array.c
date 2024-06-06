#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t i;
	int *sorted_array;

	if (heap == NULL || size == NULL)
		return (NULL);

	*size = binary_tree_size(heap);
	sorted_array = malloc(sizeof(int) * (*size));
	if (sorted_array == NULL)
		return (NULL);

	for (i = 0; i < *size; i++)
		sorted_array[i] = heap_extract(&heap);

	return (sorted_array);
}

