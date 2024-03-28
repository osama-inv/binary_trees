#include "binary_trees.h"

/**
 * binary_tree_is_root - a function that checks if a given node is a root.
 *
 * @node: is a pointer to the node to check.
 *
 * Return: 1 if the node is a root, otherwise return 0
*/

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
	{
		return (0);
	}
	return (1);
}
