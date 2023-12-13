#include "shell.h"

/**
 * bfree -  releases a pointer and then sets its address to NULL.
 * @ptr: represents the memory location of the pointer that needs to be freed.
 *
 * Return:  returns a value of 1 if the operation of freeing was successful,
 *          and it returns 0 if it was not successful.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
