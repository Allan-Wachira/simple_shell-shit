#include "shell.h"

/**
 * add_node - adds a node at the beginning of the list.
 * @str:  refers to the string field within a node.
 * @head: represents the address of a pointer directed at the head node.
 * @num:  index of the node utilized within the history context.
 *
 * Return:  return value of the function is the size of the list.
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - function that appends a node
 *      at the end of the list.
 * @str:  argument str refers to the string field of the node.
 * @head: represents the address of a pointer pointing to the head node
 *    in a list structure.
 * @num:  refers to the index of a node utilized within
 *      a history-related context.
 *
 * Return: return value of the function,
 *      indicating the size of the list.
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - function that exclusively prints the "str" element within
 *        a linked list named list_t.
 * @h:  pointer to the initial node in the list structure.
 *
 * Return: return value of the function corresponds to the size of the list.
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index -  removes a node located at a specified index
 *          within a structure or list.
 * @head: head is the memory address of a pointer pointing to
 *        the first node in a structure or list.
 * @index: specific position or index of a node that needs to
 *      be deleted within a structure or list.
 *
 * Return: returns a value of 1 when the operation is successful
 *       and 0 when it fails.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - deallocates all nodes within a list
 * @head_ptr: specifies the memory location containing
 *        the pointer to the head node
 *
 * Return:  function doesn't return any value.
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
