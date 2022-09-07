#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree.
 * @tree: The root node of the tree.
* Return: Nothing.
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *current = tree;

	if (current->left != NULL)
		binary_tree_delete(current->left);

	if (current->right != NULL)
		binary_tree_delete(current->right);

	free(current);
}
