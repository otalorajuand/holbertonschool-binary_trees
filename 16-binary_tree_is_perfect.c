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

	height_left = tree->left ? _height(tree->left) + 1 : 0;
	height_right = tree->right ? _height(tree->right) + 1 : 0;

	return (height_left > height_right ? height_left : height_right);
}

/**
 * _depth - measures the depth of a node in a binary tree.
 * @tree: A pointer to the node.
* Return: The depth of the node.
 */

size_t _depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	if (tree->parent)
		depth = _depth(tree->parent) + 1;

	return (depth);
}

/**
 * check_leave - Checks if every leave of the tree are on the same level.
 * @tree: A pointer to the root node of the tree.
 * @height: The height of the tree.
* Return: 1 if every leave are on the same level, 0 otherwise.
 */

int check_leave(const binary_tree_t *tree, size_t height)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
	{
		return (height == _depth(tree) ? 1 : 0);
	}

	if (tree->left)
		left = check_leave(tree->left, height);

	if (tree->right)
		right = check_leave(tree->right, height);

	return (left && right);
}

/**
 * is_full - checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree.
* Return: 1 if the tree is complete, 0 otherwise.
 */

int is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		return (0);

	if (tree->left)
		left = is_full(tree->left);

	if (tree->right)
		right = is_full(tree->right);

	return (!(!left != !right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
* Return: 1 if the tree is perfect, 0 otherwise.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_full(tree) && check_leave(tree, _height(tree)));
}
