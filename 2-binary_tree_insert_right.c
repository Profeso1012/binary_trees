#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the new left node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *ptr = malloc(sizeof(binary_tree_t));

	if ((ptr == NULL) || (parent == NULL))
		return (NULL);
	ptr->parent = parent;
	ptr->n = value;
	ptr->right = parent->right;
	ptr->left = NULL;

	if (parent->right != NULL)
		parent->right->parent = ptr;

	parent->right = ptr;
	return (ptr);
}
