#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * fixHeap - test
 * @node: test
 */
void fixHeap(heap_t *node)
{
	heap_t *largest = NULL;
	int temp;
        

	if (node->right)
	{
		if (node->right->n > node->left->n)
			largest = node->right;
		else
			largest = node->left;
	}
	else if (node->left)
		largest = node->left;
    else
        return;
	if (largest && largest->n > node->n)
	{
		temp = largest->n;
		largest->n = node->n;
		node->n = temp;
		fixHeap(largest);
	}
}
/**
 * getHeight - test
 * @node: test
 * Return: test
 */
int getHeight(heap_t *node)
{
	int l, r;

	if (!node)
		return (0);
	l = getHeight(node->left);
	r = getHeight(node->right);
	if (l > r)
		return (l + 1);
	return (r + 1);
}
/**
 * getLast - test
 * @height: test
 * @helper: test
 * @node: test
 * Return: test
 */
heap_t *getLast(int height, int helper, heap_t *node)
{
	heap_t *left;
	heap_t *right;

	if (helper != height)
	{
		left = getLast(height, helper + 1, node->left);
		right = getLast(height, helper + 1, node->right);
	}
	else
		return (node);
	if (right)
		return (right);
	return (left);
}
/**
 * heap_extract - test
 * @root: test
 * Return: test
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int deleted;
    int height;

	if (!*root)
		return (0);
	if (!(*root)->left && !(*root)->right)
	{
		deleted = (*root)->n;
		free(*root);
		*root = NULL;
		return (deleted);
	}
    height = getHeight(*root);
	last = getLast(height, 1, *root);
	if (last->parent->right)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;
	deleted = (*root)->n;
	(*root)->n = last->n;
	fixHeap(*root);
	free(last);
	return (deleted);
}