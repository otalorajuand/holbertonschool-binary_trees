#include "binary_trees.h"

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t size = 0, size_left = 0, size_right = 0;

	if (!tree)
		return (size);

	size_left = (!tree->left && !tree->right) ? binary_tree_leaves(tree) : 1;

}
