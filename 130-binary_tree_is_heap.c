#include "binary_trees.h"
/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}
