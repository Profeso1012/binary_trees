#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_t **queue = NULL;
	size_t front = 0, back = 0, size = 0;

	/* Enqueue root node */
	queue = malloc(sizeof(*queue) * 1024);  /* Allocate memory for the queue */
	if (!queue)
		return;

	queue[back++] = (binary_tree_t *)tree;
	size++;

	while (size > 0)
	{
		binary_tree_t *current = queue[front++];  /* Dequeue node */
		size--;

		func(current->n);  /* Process the current node */

		/* Enqueue left child */
		if (current->left)
		{
			queue[back++] = current->left;
			size++;
		}

		/* Enqueue right child */
		if (current->right)
		{
			queue[back++] = current->right;
			size++;
		}
	}

	free(queue);
}
