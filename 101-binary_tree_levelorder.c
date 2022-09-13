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
 * printCurrentLevel - Function to print all nodes at a current level
 * @tree: A pointer to the root node of the tree.
 * @level: The current level to be printed
 * @func:A function to apply to each node.
* Return: Nothing.
 */

void printCurrentLevel(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printCurrentLevel(tree->left, level - 1, func);
		printCurrentLevel(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal.
 * @tree: A pointer to the first node of the tree.
 * @func: A function to apply to each node.
* Return: Nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i = 0, height = 0;

	if (!tree || !func)
		return;

	height = _height(tree) + 1;

	for (i = 1; i <= height; i++)
		printCurrentLevel(tree, i, func);
}
