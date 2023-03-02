#include "binary_trees.h"

/**
 * binary_tree_depth - calls recursive_depth to return the depth
 * of a node in a binary tree
 *
 * @tree: tree root
 * Return: depth of the tree or 0 if tree is NULL;
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	
	return (binary_tree_depth(tree->parent + 1));
}
/**
*binary_trees_ancestor - finds lowest common ancestor of two nodes
*@first: pointer to the first node
*@second: pointer to the second node
*Return: lowest common ancestor of two nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (binary_tree_depth(first) > binary_tree_depth(second))
		return (binary_trees_ancestor(first->parent, second));

	if (binary_tree_depth(first) < binary_tree_depth(second))
		return (binary_trees_ancestor(first, second->parent));

	return (binary_trees_ancestor(first->parent, second->parent));
}
