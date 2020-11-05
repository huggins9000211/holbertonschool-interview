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
	avl_t *node;

	if (start > end)
	{
		return (NULL);
	}

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	mid = (start + end) / 2;

	node->n = array[mid];
	node->left = recur(array, start, mid - 1);
	if (node->left)
		node->left->parent = node;
	node->right = recur(array, mid + 1, end);
	if (node->right)
		node->right->parent = node;
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
	return (recur(array, 0, size - 1));
}
