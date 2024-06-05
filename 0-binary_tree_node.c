#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: parent node
 * @value: data in the node
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *ptr = malloc(sizeof(binary_tree_t));

	if (ptr == NULL)
		return (NULL);

	ptr->parent = parent;
	ptr->n = value;
	ptr->left = NULL;
	ptr->right = NULL;

	return (ptr);
}
