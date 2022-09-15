#include "binary_trees.h"


bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
		return (binary_tree_node((*(tree))->parent, value));

	if (value < (*(tree))->n)
		(*(tree))->left = bst_insert(&((*(tree))->left), value);
	else if (value > (*(tree))->n)
		(*(tree))->right = bst_insert(&((*(tree))->right), value);

	return (*tree);
}
