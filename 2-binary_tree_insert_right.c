#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the left-child of another node.
 * @parent: The parent of the new node.
 * @value: The value of the new node.
* Return: A pointer to the new node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL, *tmp_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = calloc(1, sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;

	if (parent->right == NULL)
	{
		parent->right = new_node;
	}
	else
	{
		tmp_node = parent->right;
		parent->right = new_node;
		new_node->right = tmp_node;
		new_node->right->parent = new_node;
	}

	return (new_node);
}
