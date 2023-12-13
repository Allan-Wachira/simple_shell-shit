#include "shell.h"

/**
 * _myhistory - function used to exhibit the history list.
 * Each command is shown individually with line numbers,
 * commencing at 0.
 * @info:  represents a structure that may contain possible arguments.
 * It's utilized to uphold a consistent function prototype.
 * Return: always returns 0 upon success
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - function that removes or cancels
 * an alias associated with a string.
 * @str: refers to the string serving as an alias.
 * @info: represents a parameter structure or struct.
 *
 * Return: always returns 0 upon success and 1
 * in case of an error.
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - function that assigns or establishes
 * an alias to a string.
 * @str: refers to the string serving as an alias.
 * @info: represents a parameter structure or struct.
 *
 * Return:  always returns 0 upon success
 * and 1 in case of an error.
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias -  function used to display
 * or output an alias string.
 * @node: refers to the node related to an alias.
 *
 * Return: always returns 0 upon success and 1
 * in case of an error.
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - replicates the behavior of the alias
 * command as described in the man alias
 * @info: represents a structure potentially containing arguments,
 * utilized to uphold a consistent function prototype.
 * Return:  always returns a value of 0, without exception.
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
