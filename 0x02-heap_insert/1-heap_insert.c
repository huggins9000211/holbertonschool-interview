#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Measures the height of a binary tree
 *
 * @root: Pointer to the node to measures the height
 * @value: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!*root)
	{
		heap_t *newH = binary_tree_node(NULL, value);
		*root = newH;
		return (newH);
	}
	else if (!(*root)->left)
	{
		heap_t *newH = binary_tree_node(*root, value);
		(*root)->left = newH;
		return (newH);
	}
	else if (!(*root)->right)
	{
		heap_t *newH = binary_tree_node(*root, value);
		(*root)->right = newH;
		return (newH);
	}
	return (NULL);
	/*
	*size_t rDebth = binary_tree_nodes((*root)->right);
	*size_t lDebth = binary_tree_nodes((*root)->left);
	*/
}
