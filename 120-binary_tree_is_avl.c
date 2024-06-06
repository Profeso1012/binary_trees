#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * bin_3_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t bin_3_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = bin_3_height(tree->left);
	right_height = bin_3_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 * Return: Balance factor of the tree, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bin_3_height(tree->left) - bin_3_height(tree->right));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid AVL Tree
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (1);

	balance = binary_tree_balance(tree);

	if (balance > 1 || balance < -1)
		return (0);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
