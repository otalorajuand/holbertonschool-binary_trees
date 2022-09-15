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
 * @number_nodes: The number of nodes in the binary ree.
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
 * max_condition - Checks the max condition of the heap.
 * Where each node's value is the maximum of its subtree.
 * @tree: A pointer to the first element of the three.
* Return: 1 if the tree satisfy the max condition, 0 otherwise.
 */

int max_condition(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (max_value(tree) != tree->n)
		return (0);

	return (max_condition(tree->left) && max_condition(tree->right));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree.
* Return: 1 if the tree is max binary heap, or 0 otherwise.
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_is_complete(tree) && max_condition(tree));
}


