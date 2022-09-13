#include "binary_trees.h"

binary_tree_t *lowest_common_ancestor(binary_tree_t *root, binary_tree_t *p, binary_tree_t *q)
{
	binary_tree_t *left = NULL, *right = NULL;

	if (!root || root == p || root == q)
	{
		return (root);
	}

	left = lowest_common_ancestor(root->left, p, q);
	right = lowest_common_ancestor(root->right, p, q);

	if (!left)
		return (right);
	else if (!right)
		return (left);
	else
		return (root);
}

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *root = NULL;

	root = (binary_tree_t *)first;

	while (!root->parent)
	{
		root = root->parent;
	}

	printf("%d\n", root->n);
	printf("%d\n", first->n);
	printf("%d\n", second->n);
	return (root);
}
