#include "binary_trees.h"


/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree.
* Return: 1 if the tree is complete, 0 otherwise.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		return (0);

	if (tree->left)
		left = binary_tree_is_full(tree->left);

	if (tree->right)
		right = binary_tree_is_full(tree->right);

	return (!(!left != !right));
}
