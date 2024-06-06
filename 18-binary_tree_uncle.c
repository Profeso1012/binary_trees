#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: node to check is uncle
 *
 * Return: NULL if node is NULL or as no uncle, otherwise
 *	the pointer to uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	binary_tree_t *ptr = node->parent;


	if (ptr->parent->left == ptr)
		return (ptr->parent->right);
	else
		return (ptr->parent->left);
}
