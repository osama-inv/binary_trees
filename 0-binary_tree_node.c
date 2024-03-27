#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a binary tree node.
 *
 * @parent: a pointer to the parent of the node.
 * @value: is the value to be puted on the new node.
 *
 * Return: NULL if it fails, else return a pointer to the new node.
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
