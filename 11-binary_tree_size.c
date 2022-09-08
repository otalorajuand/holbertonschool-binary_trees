#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: The tree to be measured.
* Return: The size of the tree.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, size_left = 0, size_right = 0;

	if (!tree)
		return (size);

	if (!tree->left && !tree->right)
		return (size + 1);

	size_left = tree->left ? binary_tree_size(tree->left) : 0;
	size_right = tree->right ? binary_tree_size(tree->right) : 0;

	return (size_left + size_right + 1);
}
