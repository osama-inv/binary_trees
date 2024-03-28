#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree);
int is_full_recursive(const binary_tree_t *tree);

/**
 * binary_tree_is_full - a function that checks if a binary tree is full.
 *
 * @tree: is a pointer to the root node of the tree to check.
 *
 * Return: if tree is NULL, return 0
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_full_recursive(tree));
}

/**
 * is_full_recursive - a function that checks if a binary tree,
 *	is full recursively.
 *
 * @tree: is a pointer to the root node of the tree to check.
 *
 * Return: if tree is not NULL return 0, otherwise return 1.
*/

int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)

			return (0);
	}
	return (1);
}
