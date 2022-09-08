#include "binary_trees.h"

/**
 * _size - measures the size of a binary tree.
 * @tree: The tree to be measured.
* Return: The size of the tree.
 */

size_t _size(const binary_tree_t *tree)
{
	size_t size = 0, size_left = 0, size_right = 0;

	if (!tree)
		return (size);

	if (!tree->left && !tree->right)
		return (size + 1);

	size_left = tree->left ? _size(tree->left) : 0;
	size_right = tree->right ? _size(tree->right) : 0;

	return (size_left + size_right + 1);
}

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree.
* Return: 1 if the tree is complete, 0 otherwise.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_size(tree->left) == _size(tree->right) ? 1 : 0);
}
