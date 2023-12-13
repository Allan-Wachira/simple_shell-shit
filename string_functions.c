#include "shell.h"

/**
 * _strlen -  is a function that provides the
 * length of a string as its output.
 * @s: refers to the string for which the
 * length needs to be determined or checked.
 *
 * Return:  returns an integer
 * representing the length of a string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - is a function used to compare two
 * strings based on their lexicographic order.
 * @s2: refers to the second string
 * being considered or used.
 * @s1: refers to the first string being used
 *
 * Return: returns a negative value if s1 is
 * less than s2, a positive value if s1
 * is greater than s2, and zero if s1 equals s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - verifies if the string 'needle'
 * begins with the content of the string 'haystack'.
 * @needle: refers to the specific substring that
 * needs to be located or found within another string.
 * @haystack:  represents the string in
 * which the search operation will be conducted.
 *
 * Return:  returns the address of the next character
 * in the haystack string or
 * NULL if there isn't a next character.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - a function used to combine or
 * join two strings together.
 * @src: represents the buffer or source of data
 * @dest: refers to the buffer where
 * the data will be copied or stored.
 *
 * Return: returns a pointer pointing
 * to the destination buffer.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
