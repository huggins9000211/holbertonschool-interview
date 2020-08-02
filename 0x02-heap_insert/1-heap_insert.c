#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - Entry point
 *
 * @tree: tree
 *
 * Return: Always 0 (Success)
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int l;

	if (!tree)
		return (0);
	if (!binary_tree_is_leaf(tree))
		l = 1;
	else
		l = 0;
	l = l + binary_tree_nodes(tree->left);
	l = l + binary_tree_nodes(tree->right);
	return (l);
}

/**
 * binary_tree_node - Measures the height of a binary tree
 *
 * @root: Pointer to the node to measures the height
 * @value: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (! *root)
    {
        heap_t *newH = binary_tree_node(NULL, value);
        *root = newH;
        return (newH);
    }
    else if (! (*root)->left)
    {
        heap_t *newH = binary_tree_node(*root, value);
        (*root)->left = newH;
        return (newH);
    }
    else if (! (*root)->right)
    {
        heap_t *newH = binary_tree_node(*root, value);
        (*root)->right = newH;
        return (newH);
    }
    size_t rDebth = binary_tree_nodes((*root)->right);
    size_t lDebth = binary_tree_nodes((*root)->left);

}