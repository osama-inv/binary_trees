#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Heap tree.
 *
 * @array: points to the 1fr element.
 * @size: The number of element in the array.
 *
 * Return: A pointer to the root node.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int index;
	heap_t *root = NULL;

	for (index = 0; index < size; index++)
		heap_insert(&root, array[index]);

	return (root);
}
