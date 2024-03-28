#include "binary_trees.h"

/**
 * binary_tree_balance - a function that measures the balance factor,
 *	of a binary tree.
 *
 * @tree: is a pointer to the root node of the tree,
 *	to measure the balance factor.
 *
 * Return: if tree is NULL, return 0
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - a function that measures the height of a binary tree.
 *
 * @tree: is a  pointer to the root node of the tree to measure the height.
 *
 * Return: if tree is NULL, return 0
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rig = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((lef > rig) ? lef : rig);
	}
	return (0);
}
