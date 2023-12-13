#include "shell.h"

/**
 * is_chain -  function used to check whether the current character
 * in the buffer is a chain delimiter.
 * @buf: represents a character buffer or an array of characters.
 * @info: @info: structure used to hold parameters or information.
 * @p: refers to the memory location or address of
 * the current position within the buffer.
 *
 * Return: returns a value of 1 if it's a
 * chain delimiter and 0 if it's not.
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain -  function used to verify whether the chaining process
 * should continue based on the last status.
 * @len:  represents the size or extent of the buffer.
 * @buf: refers to the character buffer or an array of characters.
 * @i: represents the initial position within the buffer.
 * @info: structure used to hold parameters or information.
 *
 * @p: refers to the memory location or address of
 * the current position within the buffer.
 *
 * Return: does not return any value
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - function designed to substitute aliases
 * within the tokenized string.
 * @info:  structure used to hold parameters or information.
 *
 * Return:  returns a value of 1 if the replacement occurred,
 * and it returns 0 if it did not happen.
 *
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars -  function used to substitute variables
 * within the tokenized string.
 * @info: structure used to hold parameters or information.
 *
 * Return:  returns a value of 1 if the replacement occurred,
 * and it returns 0 if it did not happen.
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - function designed to substitute or
 * exchange one string with another.
 * @new: refers to the updated or new string
 * @old: represents the memory location or address of the old string.
 *
 * Return:  function returns 1 if the replacement has been
 * made and 0 if it hasn't been replaced.
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
