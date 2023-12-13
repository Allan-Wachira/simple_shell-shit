#include "shell.h"

/**
 **_memset - is used to fill memory by repeatedly
 *inserting a specific byte throughout
 *@b: is the specific byte used to fill the
 *memory indicated by @s.
 *@n: represents the quantity of bytes that
 *will be used to fill the memory.
 *@s: refers to a pointer that indicates
 *the location in the memory.
 *Return: This line indicates that the function
 *returns a pointer pointing to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - is a function used to release or
 * free a collection of strings.
 * @pp:  represents a collection of strings,
 * essentially a string array or list of strings.
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc -  is a function that adjusts
 * or resizes a previously allocated block of memory.
 * @new_size:  represents the size, in bytes,
 * of a newly allocated block of memory.
 * @ptr: is a pointer referring to a block of
 * memory previously allocated using malloc.
 * @old_size: represents the size, in bytes,
 * of the previous block of memory
 *
 * Return: the function returns a pointer to the
 * old block, referencing its name or identifier.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
