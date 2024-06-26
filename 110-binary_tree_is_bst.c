#include "binary_trees.h"

int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst_helper(const binary_tree_t *tree, int low, int high);
/**
 * binary_tree_is_bst - a function that checks if a binary tree,
 *	is a valid Binary Search Tree.
 *
 * @tree: is a pointer to the root node of the tree to check.
 *
 * Return: if tree is a valid BST return 1,
 *	otherwise return 0
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - a function that checks if a binary tree,
 *	is a valid binary search tree.
 *
 * @tree: is a pointer to the root node of the tree to check.
 * @low: is the value of the smallest node visited thus far.
 * @high: is the value of the largest node visited this far.
 *
 * Return: If the tree is a valid BST return 1,
 *	otherwise return 0
*/

int is_bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
		{
			return (0);
		}
		return (is_bst_helper(tree->left, low, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}
