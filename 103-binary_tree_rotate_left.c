#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;
	temp = new_root->left;

	new_root->left = tree;
	tree->parent = new_root;
	tree->right = temp;
	if (temp)
		temp->parent = tree;
	new_root->parent = NULL;

	return (new_root);
}
