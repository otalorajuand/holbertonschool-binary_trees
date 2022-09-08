#include "binary_trees.h"

/**
 * binary_tree_leaves - measures the number of leaves of a binary tree.
 * @tree: The tree to be measured.
* Return: The leaves of the tree.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0, leaves_left = 0, leaves_right = 0;

	if (!tree)
		return (leaves);

	if (!tree->left && !tree->right)
		return (leaves + 1);

	leaves_left = tree->left ? binary_tree_leaves(tree->left) : 0;
	leaves_right = tree->right ? binary_tree_leaves(tree->right) : 0;

	return (leaves_left + leaves_right);
}
