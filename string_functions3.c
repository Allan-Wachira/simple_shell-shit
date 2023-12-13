#include "shell.h"

/**
 **_strncpy - used to duplicate a string.
 *@n: represents the maximum number of bytes to be utilized.
 *@src: represents the second string being considered.
 *@dest: initial or first string involved.
 *Return: returns concatenated string as its output.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat -  function used to append two strings together.
 *@n: represents the maximum number of bytes to be utilized.
 *@dest:  initial or first string involved.
 *@src:  represents the second string being considered.
 *Return: returns concatenated string as its output.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - used to find the position of a specific character within a string.
 *@c: represents the character that is being searched for within the string.
 *@s: represents the string that needs to be analyzed.
 *Return: returns a pointer pointing to the memory area denoted by s.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
