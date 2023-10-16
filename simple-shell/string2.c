#include "shell.h"

/**
 * _printchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print - prints a string
 * @str: pointer to string
 */

void _print(char *str)
{
	int i = 0;

	while (str[i])
	{
		_printchar(str[i]);
		i++;
	}
}
