#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (!*tree)
			return (NULL);
		return (*tree);
	}

	if (value < (*tree)->n)
		(*tree)->left = avl_insert(&((*tree)->left), value);
	else if (value > (*tree)->n)
		(*tree)->right = avl_insert(&((*tree)->right), value);
	else
		return (NULL);

	(*tree)->height = 1 + MAX(height((*tree)->left), height((*tree)->right));

	int balance = balance_factor(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return (avl_rotate_right(*tree));
	if (balance < -1 && value > (*tree)->right->n)
		return (avl_rotate_left(*tree));
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = avl_rotate_left((*tree)->left);
		return (avl_rotate_right(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = avl_rotate_right((*tree)->right);
		return (avl_rotate_left(*tree));
	}

	return (*tree);
}
