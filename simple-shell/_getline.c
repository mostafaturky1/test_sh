#include "shell.h"

char *_getline(void)
{
    char *command = NULL;
    size_t command_size = 0;

    getline(&command, &command_size, stdin);
    return (command);
}

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
