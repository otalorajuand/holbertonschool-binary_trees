#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree.
 * @tree: The tree to be measured.
* Return: The nodes of the tree.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0, nodes_left = 0, nodes_right = 0;

	if (!tree || (!tree->left && !tree->right))
		return (nodes);

	nodes_left = tree->left ? binary_tree_nodes(tree->left) : 0;
	nodes_right = tree->right ? binary_tree_nodes(tree->right) : 0;

	return (nodes_left + nodes_right + 1);
}
