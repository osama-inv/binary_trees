#include "binary_trees.h"

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
levelorder_queue_t *create_node(binary_tree_t *node);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void free_queue(levelorder_queue_t *head);
void pop(levelorder_queue_t **head);

/**
 * binary_tree_levelorder - a function that goes through a bin-tree by level-order traversal.
 *
 * @tree: is a pointer to the root node of the tree to traverse.
 * @func: is a pointer to a function to call for each node.
 *
 * Return: void
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
	{
		return;
	}
	head = tail = create_node((binary_tree_t *)tree);

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}

/**
 * create_node - a function that creates a new levelorder_queue_t node.
 *
 * @node: is the binary tree node for the new node to contain.
 *
 * Return: if an error occurs, return NULL.
 *	otherwise, return a pointer to the new node.
*/
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));

	if (new == NULL)
	{
		return (NULL);
	}
	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * pint_push - a function that runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 *
 * @node: is the binary tree node to print and push.
 * @head: is a double pointer to the head of the queue.
 * @tail: is a double pointer to the tail of the queue.
 * @func: is a pointer to the function to call on @node.
 *
 * Description: on malloc failure, exits with a status code of 1.
 *
 * Return: void
*/

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);

	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * free_queue - a function that frees a levelorder_queue_t queue.
 *
 * @head: is a pointer to the head of the queue.
 *
 * Return: void
*/

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pop - a function that pops the head of a levelorder_queue_t queue.
 *
 * @head: is a double pointer to the head of the queue.
 *
 * Return: void
*/

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}
