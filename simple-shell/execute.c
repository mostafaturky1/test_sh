#include "shell.h"

/**
 * execute - Execute a command with given arguments.
 * @arguments: An array of strings representing the command and its arguments.
 *
 * This function to executing a command with the specified arguments.
 *
 * Return: Always returns 0.
 */

int execute(char *arguments[])
{
	char *temp = NULL, *path = NULL;
	list_path *head = NULL;
	void (*exist)(char **);

	if (!arguments || !arguments[0])
	{
		return (0);
	}
	temp = _getenv("PATH");
	head = pathstrok(temp);
	path = any_Path(arguments[0], head);
	exist = isBuild(arguments);
	if (exist)
	{
		exist(arguments);
		return (0);
	}
	else if (!path)
	{
		exec(arguments[0], arguments, environ);
	}
	else if (path)
	{
		free(arguments[0]);
		arguments[0] = path;
		exec(arguments[0], arguments, environ);
	}
	return (0);
}

/**
 * isExist - Check for a command's existence or exit condition.
 * @command_length: The length of the command input.
 * @command: The command input itself (unused parameter).
 *
 * This function checks the length of the command input. If the length is -1.
 */

void isExist(int command_length, char *command)
{
		(void)command;
	if (command_length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_print("\n");
			free(command);
		}
		exit(0);
	}
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
