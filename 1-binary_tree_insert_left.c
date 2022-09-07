#include "binary_trees.h"

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL, *tmp_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = calloc(1, sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;

	if (parent->left == NULL)
	{
		parent->left = new_node;
	}
	else
	{
		tmp_node = parent->left;
		parent->left = new_node;
		new_node->left = tmp_node;
		new_node->left->parent = new_node;
	}

	return (new_node);

}
