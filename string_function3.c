#include "shell.h"

/**
 * _strcpy - replicate or duplicate a string
 * @src: refers to the source or the origin of string
 * @dest:  represents the target where a string will be placed.
 *
 * Return: returns a pointer pointing to the destination.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - create a copy of a string.
 * @str: string that needs to be duplicated or copied.
 *
 * Return:  returns a pointer pointing to the duplicated string;
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - display or print a given input string.
 *@str: string that needs to be displayed or printed.
 *
 * Return: function does not return any value.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - display or print the character c on the standard output (stdout).
 * @c: represents the character intended to be printed or displayed.
 *
 * Return:  returns 1 if successful. In case of an error,
 *          it returns -1, and the error number (errno) is set accordingly.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
