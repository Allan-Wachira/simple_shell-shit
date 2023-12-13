#include "shell.h"

/**
 * _erratoi - function that transforms a
 * string into an integer.
 * @s: represents the string that
 * needs to undergo conversion.
 * Return: function returns 0 if there are no
 * numbers found in the string, it returns the
 * converted number if there are any,
 * and it returns -1 in case of an error.
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - used to display or output an error message.
 * @estr: a string that contains a specific type of error.
 * @info:  represents the struct containing information
 * about parameters and return values.
 * Return: returns 0 if there are no numbers present in
 * the string and returns the converted number otherwise
 * It returns -1 in case of an error.
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d -  responsible for displaying or an
 * integer number in the decimal (base 10) format
 * @fd: represents the file descriptor used
 * for writing purposes.
 * @input: refers to the provided input.
 *
 * Return: returns the count of printed characters
 * as its output.
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number -  is a conversion function,
 * similar to itoa, used to convert numbers.
 * @base: refers to the numerical base used for conversion.
 * @flags: represents the flags or options used as arguments.
 * @num: refers to the numerical value or number being considered.
 * @flags: represents the flags or options used as arguments.
 *
 * Return: returns a string as its output.
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - replaces the first occurrence
 * of '#' in a string with '\0' (null terminator).
 * @buf:  refers to the memory location of the string
 * that needs to be altered or modified.
 *
 * Return: function always returns a value of 0,
 * without exception;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
