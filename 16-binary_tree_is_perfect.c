#include "binary_trees.h"

/**
*size - measures the size of a binary tree
*@tree: pointer to the root node of the tree to measure the size
*Return: size of the tree
*/
int size(const binary_tree_t *tree)
{
	int count = 1;

	if (tree == NULL)
		return (0);

	count += size(tree->left);
	count += size(tree->right);

	return (count);
}

/**
*binary_tree_height - measures the height of a binary tree
*@tree: pointer to the root node of the tree to measure the height
*Return: height of binary tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
		return (left);
	else
		return (right);

	return (0);
}

/**
*binary_tree_is_perfect - checks if a binary tree is perfect
*@tree: pointer to the root node of the tree to check
*Return: tree
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l_node, r_node, l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	l_node = size(tree->left);
	r_node = size(tree->right);

	if (l_height == r_height)
		if (l_node == r_node)
			return (1);

	return (0);
}
