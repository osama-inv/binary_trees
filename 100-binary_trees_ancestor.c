#include "binary_trees.h"

/**
 * binary_trees_ancestor - a function that finds,
 *	the lowest common ancestor of two nodes.
 *
 * @first: is a pointer to the first node.
 * @second: is a pointer to the second node.
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 *         if no common ancestor was found, return NULL
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mom, *pop;

	if (!first || !second)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}
	mom = first->parent, pop = second->parent;
	if (first == pop || !mom || (!mom->parent && pop))
	{
		return (binary_trees_ancestor(first, pop));
	}
	else if (mom == second || !pop || (!pop->parent && mom))
	{
		return (binary_trees_ancestor(mom, second));
	}
	return (binary_trees_ancestor(mom, pop));
}
