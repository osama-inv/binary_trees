#include "binary_trees.h"

/**
 * array_to_avl - a function that builds an AVL tree from an array.
 *
 * @array: is a pointer to the first element of the array to be converted.
 * @size: is the number of element in the array.
 *
 * Return: a pointer to the root node of the created AVL tree,
 *	and return NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index, jndex;

	if (array == NULL)
	{
		return (NULL);
	}
	for (index = 0; index < size; index++)
	{
		for (jndex = 0; jndex < index; jndex++)
		{
			if (array[jndex] == array[index])
			{
				break;
			}
		}
		if (jndex == index)
		{
			if (avl_insert(&tree, array[index]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (tree);
}
