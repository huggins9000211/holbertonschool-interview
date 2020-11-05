#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * recur - Prints an array of integers
 *
 * @array: The array to be printed
 * @start: Size of the array
 * @end: test
 *
 * Return: The height of the tree starting at @node
 */
avl_t *recur(int *array, int start, int end)
{
	int mid;
	avl_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);

	if (start > end)
	{
		return (NULL);
	}
	mid = (start + end) / 2;

	node->n = array[mid];
	node->left = recur(array, start, mid - 1);
	node->right = recur(array, mid + 1, end);
	return (node);
}

/**
 * sorted_array_to_avl - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Size of the array
 *
 * Return: The height of the tree starting at @node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	return (recur(array, start, end));
}
