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

/**
 * free_Arguments - Free memory allocated for an array of strings.
 * @arguments: The array of strings to be freed.
 *
 * This function to releasing memory allocated for an array of strings.
 */

void free_Arguments(char **arguments)
{
	int i;

	if (arguments == NULL) return;

	for (i = 0; arguments[i] != NULL; i++)
    {	
		if (arguments[i] == NULL) continue;
		
		if(arguments[i]) free(arguments[i]);
    }
	
	if(arguments) free(arguments);
}
