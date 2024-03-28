#include "binary_trees.h"

int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
size_t height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - a function that checks if a binary tree,
 *	is a valid AVL Tree.
 *
 * @tree: is a pointer to the root node of the tree to check.
 *
 * Return: if tree is a valid AVL Tree return 1,
 *	otherwise return 0
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - a function that checks if a binary tree is a valid AVL tree.
 *
 * @tree: is a pointer to the root node of the tree to check.
 * @lo: is the value of the smallest node visited thus far.
 * @hi: is the value of the largest node visited this far.
 *
 * Return: if the tree is a valid AVL tree return 1,
 *	otherwise return 0
*/

int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
		{
			return (0);
		}
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
		{
			return (0);
		}
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * height - a function that measures the height of a binary tree.
 *
 * @tree: is a pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL return 0, else return the height
*/

size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
