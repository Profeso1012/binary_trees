#include "binary_trees.h"

/**
 * get_depth - gets the depth of the leftmost leaf
 * @node: pointer to the root node of the tree
 *
 * Return: depth of the leftmost leaf
 */
int get_depth(const binary_tree_t *node)
{
	int depth = 0;

	while (node != NULL)
	{
		depth++;
		node = node->left;
	}
	return (depth);
}

/**
 * is_perfect_rec - function to check if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * @depth: depth of the tree
 * @level: current level in the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_rec(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_rec(tree->left, depth, level + 1) &&
		   is_perfect_rec(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = get_depth(tree);
	return (is_perfect_rec(tree, depth, 0));
}
