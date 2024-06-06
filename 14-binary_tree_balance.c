#include "binary_trees.h"

/**
 * b_t_h - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of the tree, or 0 if tree is NULL
 */
size_t b_t_h(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = b_t_h(tree->left);
	size_t right_height = b_t_h(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = tree->left ? (int)b_t_h(tree->left) : 0;
	int right_height = tree->right ? (int)b_t_h(tree->right) : 0;

	return (left_height - right_height);
}

