#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree.
* Return: a pointer to the new root node of the tree once rotated.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (!tree)
		return (NULL);

	new_root = tree->right;
	tree->right = new_root->left;
	tree->parent = new_root;
	new_root->left = tree;

	return (new_root);
}
