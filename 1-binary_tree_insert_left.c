#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the new left node or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *ptr = malloc(sizeof(binary_tree_t));

	if ((ptr == NULL) || (parent == NULL))
		return (NULL);
	ptr->parent = parent;
	ptr->n = value;
	ptr->right = NULL;
	ptr->left = parent->left;

	if (parent->left != NULL)
		parent->left->parent = ptr;

	parent->left = ptr;
	return (ptr);
}
