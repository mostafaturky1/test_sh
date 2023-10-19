#include "shell.h"

/**
 * _getenv - gets the value of the global variable
 * @name: name of the global variable
 * Return: string of value
 */
char *_getenv(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}
/**
 * contol_C - Handle SIGINT signal (Ctrl+C) by displaying a prompt.
 * @sig_num: The signal number.
 *
 * This function is invoked when the SIGINT signal is received (Ctrl+C).
 */


void contol_C(int sig_num)
{
	char *prompt = "\n($) ";

	if (sig_num == SIGINT)
	{
		_print(prompt);
	}
}

list_path *pathstrok(char *path)
{
	list_path *head = NULL;
	char *token;
	char *cpath = _strdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = end_node(&head, token);
		token = strtok(NULL, ":");
	}

	free(cpath);
	return (head);
}

/**
 * pro_Exit - exits the shell with or without a return of status n
 * @arguments: array of words of the entered line
 */
void pro_Exit(char **arguments)
{
	int n;

	if (arguments[1])
	{
		n = _converter(arguments[1]);
		if (n <= -1)
			n = 2;
		free_Arguments(arguments);
		exit(n);
	}
	free_Arguments(arguments);
	exit(0);
}

/**
 * _converter - converts a string into an integer
 *@str: pointer to a string
 *Return: the integer
 */
int _converter(char *str)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;
	while (!((str[i] >= '0') && (str[i] <= '9')) && (str[i] != '\0'))
	{
		if (str[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (str[i] - '0'));
		i++;
	}
	return (integer);
}

