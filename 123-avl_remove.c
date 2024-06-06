#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the desired
 * value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			avl_t *temp = root->left ? root->left : root->right;
			free(root);
			return (temp);
		}

		avl_t *temp = root->right;
		while (temp->left)
			temp = temp->left;

		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	if (!root)
		return (NULL);

	root->height = 1 + MAX(avl_height(root->left), avl_height(root->right));

	int balance = avl_balance(root);

	if (balance > 1 && avl_balance(root->left) >= 0)
		return (avl_rotate_right(root));

	if (balance > 1 && avl_balance(root->left) < 0)
	{
		root->left = avl_rotate_left(root->left);
		return (avl_rotate_right(root));
	}

	if (balance < -1 && avl_balance(root->right) <= 0)
		return (avl_rotate_left(root));

	if (balance < -1 && avl_balance(root->right) > 0)
	{
		root->right = avl_rotate_right(root->right);
		return (avl_rotate_left(root));
	}

	return (root);
}
