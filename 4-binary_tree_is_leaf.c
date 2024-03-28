#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf.
 *
 * @node: is a pointer to the node to check.
 *
 * Return: 1 if a node is a leaf, otherwise return 0.
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
	{
		return (0);
	}
	return (1);
}
