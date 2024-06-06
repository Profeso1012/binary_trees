#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	binary_tree_t **queue = malloc(sizeof(*queue) * 1024);  /* Allocate memory for the queue */
	if (!queue)
		return (0);

	size_t front = 0, back = 0;
	int found_null = 0;

	queue[back++] = (binary_tree_t *)tree;

	while (front < back)
	{
		binary_tree_t *current = queue[front++];

		if (current)
		{
			if (found_null)
			{
				free(queue);
				return (0);  /* If we found a null node before, and now we see a non-null node */
			}

			queue[back++] = current->left;
			queue[back++] = current->right;
		}
		else
		{
			found_null = 1;
		}
	}

	free(queue);
	return (1);
}
