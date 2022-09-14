#include "binary_trees.h"

/**
 * max_value - Finds the maximum value of a binary tree.
 * @tree: A pointer to the root node of the tree.
* Return: The maximum value of the tree.
 */


int max_value(const binary_tree_t *tree)
{
	int res = 0, left_res = 0, right_res = 0;

	if (!tree)
		return (0);

	res = tree->n;
	left_res = max_value(tree->left);
	right_res = max_value(tree->right);

	if (left_res > res)
		res = left_res;
	if (right_res > res)
		res = right_res;

	return (res);
}

/**
 * min_value - Finds the minimum value of a binary tree.
 * @tree: A pointer to the root node of the tree.
* Return: The minimum value of the tree.
 */

int min_value(const binary_tree_t *tree)
{
	int res = 0, left_res = 0, right_res = 0;

	if (!tree)
		return (INT_MAX);

	res = tree->n;
	left_res = min_value(tree->left);
	right_res = min_value(tree->right);

	if (left_res < res)
		res = left_res;
	if (right_res < res)
		res = right_res;

	return (res);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the first element of the three.
* Return: 1 if the tree is bst, 0 otherwise.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && max_value(tree->left) >= tree->n)
		return (0);

	if (tree->right != NULL && min_value(tree->right) <= tree->n)
		return (0);

	if (binary_tree_is_bst(tree->left) == 0 ||
			binary_tree_is_bst(tree->right) == 0)
		return (0);

	return (1);
}
