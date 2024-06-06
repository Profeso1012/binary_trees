#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *parent;

    if (tree == NULL)
	   return (NULL);

    parent = NULL;
    while (*tree != NULL)
    {
	   if (value == (*tree)->n)
		  return (NULL); /* Value already exists in the tree */

	   parent = *tree;

	   if (value < parent->n)
		  tree = &(*tree)->left;
	   else
		  tree = &(*tree)->right;
    }

    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
	   return (NULL);

    if (parent == NULL)
	   *tree = new_node; /* Insert as root node */
    else if (value < parent->n)
	   parent->left = new_node;
    else
	   parent->right = new_node;

    return (new_node);
}
