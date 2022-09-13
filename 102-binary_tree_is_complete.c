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
 * is_complete_aux - Let use the number of node and the index
 * as parameters for the checking of completness of a binary tree.
 * @root: A pointer to the root node of the binary tree.
 * @index: Represents the position of the node in an array representation.
 * @number_nodes: The number of nodes in the binary tree.
* Return: 1 if the tree is complete, 0 if not.
 */

int is_complete_aux(const binary_tree_t *root, unsigned int index,
		unsigned int number_nodes)
{
	if (!root)
		return (1);

	if (index >= number_nodes)
		return (0);

	return (is_complete_aux(root->left, 2 * index + 1, number_nodes) &&
			is_complete_aux(root->right, 2 * index + 2, number_nodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the binary tree.
* Return: 1 if the tree is complete, 0 if not.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int number_of_nodes = 0;

	if (!tree)
		return (0);

	number_of_nodes = _size(tree);

	return (is_complete_aux(tree, 0, number_of_nodes));
}
