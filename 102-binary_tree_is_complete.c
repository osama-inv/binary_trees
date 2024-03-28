#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree);
levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);

/**
 * binary_tree_is_complete - a function that checks if a binary tree is complete.
 *
 * @tree: is a pointer to the root node of the tree to check.
 *
 * Return: if tree is NULL, return 0
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{

	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = create_node((binary_tree_t *)tree);

	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}

/**
 * create_node - a function that creates a new levelorder_queue_t node.
 *
 * @node: is the binary tree node for the new node to contain.
 *
 * Return: if an error occurs, return NULL
 *	Otherwise, return a pointer to the new node.
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
 * push - a function that pushes a node to the back,
 *	of a levelorder_queue_t queue.
 *
 * @node: is the binary tree node to print and push.
 * @head: is a double pointer to the head of the queue.
 * @tail: is a double pointer to the tail of the queue.
 *
 * Description: on malloc failure, exits with a status code of 1.
 *
 * Return: void
*/

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
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
