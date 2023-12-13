#include "shell.h"

/**
 * interactive - will provide a true value
 * if the shell is in interactive mode.
 * @info: represents a structure related to addresses.
 *
 * Return: returns a value of 1 if the mode is interactive,
 *          and it returns 0 if it's not interactive.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim -  is a function that verifies
 * whether a character is a delimiter or not.
 * @delim: represents the string of
 * characters used as delimiters.
 * @c: refers to the character that
 * needs to be checked or examined.
 * Return: returns a value of 1 if the condition is true
 * and returns 0 if the condition is false.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - is a function used to verify if
 *a character is an alphabetic character or not.
 *@c:  represents the character to be
 *entered or provided as input.
 *Return: returns a value of 1 if the character 'c' is
 *an alphabet letter, and it returns 0
 *if it's not an alphabet letter.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi -  is a function that changes or
 *translates a string into an integer value.
 *@s: is the string that needs to undergo conversion.
 *Return:  returns 0 if there are no numbers
 *present in the string; otherwise,it returns
 *the converted number.
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
