#include "binary_trees.h"

/**
 * size_t binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t deep;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	deep = binary_tree_depth(tree->parent) + 1;
	return (deep);
}
