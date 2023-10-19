#include "shell.h"

/**
 * execute - Execute a command with given arguments.
 * @arguments: An array of strings representing the command and its arguments.
 *
 * This function to executing a command with the specified arguments.
 *
 * Return: Always returns 0.
 */

int execute(char *tokens[])
{
	char *temp = NULL, *path = NULL;
	list_path *head = NULL;
	void (*exist)(char **);

	_print("execute");

	if (!tokens || !tokens[0])
	{
		if (isatty(STDIN_FILENO))
		{
			_print("\n");
		}

		return (0);
	}

	temp = _getenv("PATH");
	head = pathstrok(temp);
	path = any_Path(tokens[0], head);
	exist = isBuild(tokens);
	free(head);
	
	if (exist)
	{
		exist(tokens);
		return (0);
	}
	else if (!path)
	{
		exec(tokens[0], tokens, environ);
	}
	else if (path)
	{
		tokens[0] = path;
		exec(tokens[0], tokens, environ);
	}
	return (0);
}

/**
 * run - Read and execute a command from the user.
 *
 * This function reads a command from the user via standard input.
 *
 * Return: exit status of the executed command or 0 if no command is entered.
 */

int run(void)
{
	int  exited = 0;
	char *line = NULL, **tokens = NULL;
	size_t line_size = 0;
	ssize_t length = 0;

	line_size = getline(&line, &line_size, stdin);
	
	if (!isExist(line_size, line)){
		free(line);
		return 1;
	}
	
	_print(line);

	if (length > 0 && line[line_size] == '\n')
	{
		line[line_size] = '\0';
	}

	tokens = tokenize(line, " \n");
	exited = execute(tokens);

	free_Arguments(tokens);
	free(line);
	return (exited);
}

/**
 * isExist - Check for a command's existence or exit condition.
 * @command_length: The length of the command input.
 * @command: The command input itself (unused parameter).
 *
 * This function checks the length of the command input. If the length is -1.
 */

int isExist(int command_length, char *command)
{
	if (command == NULL) return 0;

	if (command_length == -1) return 0;

	return 1;
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
