#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node.
 * @parent: The parent of the new node.
 * @value: The value of the new node.
* Return: A Pointer to the new node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));

	new_node->parent = parent;
	new_node->n = value;

	return (new_node);
}
