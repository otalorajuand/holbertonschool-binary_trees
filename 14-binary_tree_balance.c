#include "binary_trees.h"

/**
 * _height - measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
* Return: The height of the tree.
 */

size_t _height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	height_left = tree->left ? _height(tree->left) + 1 : 0;
	height_right = tree->right ? _height(tree->right) + 1 : 0;

	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: The tree to be checked.
* Return: Nothing.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	height_left = _height(tree->left);
	height_right = _height(tree->right);

	return (height_left - height_right);
}
