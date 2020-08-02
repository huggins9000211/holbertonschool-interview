#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Measures the height of a binary tree
 *
 * @parent: Pointer to the node to measures the height
 * @value: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
