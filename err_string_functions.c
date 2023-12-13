#include "shell.h"

/**
 *_eputs - designed to output a provided string.
 * @str: string intended for printing.
 *
 * Return: Null
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character 'c' to the
 * standard error stream (stderr)
 * @c: character given for printing
 *
 * Return: returns 1. On encountering an error, it returns -1,
 * setting the appropriate error code in errno.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @fd: the file used for writing.
 * @c: character given for writing
 *
 * Return: returns 1. On encountering an error, it returns -1,
 * setting the appropriate error code in errno.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 *_putsfd - responsible for printing an input string.
 * @fd: the file used for writing.
 * @str:the string intended for printing.
 *
 * Return: returns the count of characters
 * that have been printed.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
