#include "shell.h"

/**
 * list_len - calculates the size or
 * length of a linked list.
 * @h: refers to the pointer pointing to
 * the initial node of the sequence.
 *
 * Return: return value of the code is
 * the size or length of the list.
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - converts the string elements
 * of a list into an array of strings.
 * @head: pointer referencing the first
 * node in a data structure.
 *
 * Return: function returns an array consisting of strings.
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - displays all the elements
 * present in a linked list named list_t.
 * @h:  pointer to the first node in a data structure.
 *
 * Return: return value of this particular
 * code is the size of a list.
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - fetches a node whose
 * string commences with a specified prefix.
 * @prefix: used to match and find nodes
 * start with a particular prefix.
 * @node: refers to a pointer directed
 * to the head of the list.
 * @c:  signifies the subsequent character
 * following the prefix to be matched.
 *
 * Return: returns either a node that matches the criteria
 *    or a null value.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index -  retrieves the position or index of
 * a particular node within a structure or a list.
 * @node: pointer referencing the specific
 * node being referenced upon.
 * @head: pointer referring to the head of
 * the list being referencedd.
 *
 * Return: return value will be the index of the node
 * if found, otherwise -1 will be returned.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
