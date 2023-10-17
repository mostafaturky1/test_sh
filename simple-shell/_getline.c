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
 * converter - converts a string into an integer
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

/**
* isBuild - checks if the command is a buildin
* @arguments: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*isBuild(char **arguments))(char **arv)
{
	int i, j;
	mybuild T[] = {
		{"exit", pro_Exit},
		{"env", print_env},
		/*{"setenv", _setenv},
		{"unsetenv", _unsetenv},*/
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == arguments[0][j])
		{
			for (j = 0; arguments[0][j]; j++)
			{
				if (T[i].name[j] != arguments[0][j])
					break;
			}
			if (!arguments[0][j])
				return (T[i].func);
		}
	}
	return (0);
}
