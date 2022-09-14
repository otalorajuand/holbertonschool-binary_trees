#include "binary_trees.h"

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


int main(void)
{
    binary_tree_t *root;
    int bst;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 10);

    binary_tree_print(root);
    bst = min_value(root);
    printf("min: %d\n", bst);

    return (bst);
}
