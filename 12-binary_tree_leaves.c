#include "binary_trees.h"

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: root node
 *
 * Return: 0 If tree is NULL oterwise no of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leafss;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	leafss = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
	return (leafss);
}

