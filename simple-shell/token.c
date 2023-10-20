#include "shell.h"

/**
 * tokenize - Split a string into tokens using a specified delimiter.
 * @line: The input string to tokenize.
 * @delim: The delimiter used to split the string.
 *
 * Return: An array of strings containing the tokens or NULL on failure.
 */

char **tokenize(char *line, const char *delim)
{
	int num_token = 0;
	int i = 0;
	int j = 0;
	char **tokens = NULL;
	char *token = NULL, *copy = NULL;
	int maxTokenLength = 0;

	if (line == NULL || delim == NULL)
	return (NULL);
	copy = malloc(_strlen(line) + 1);
	if (copy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	_strcpy(copy, line);
	token = strtok(line, delim);
	while (token != NULL)
	{
		num_token++;
		if (_strlen(token) > maxTokenLength)
		maxTokenLength = _strlen(token);
		token = strtok(NULL, delim);
	}

	tokens = (char **)malloc(num_token * sizeof(char *));
	for (j = 0; j <= num_token; j++)
	{
		tokens[j] = (char *)malloc((maxTokenLength + 1) * sizeof(char));
	}
	token = strtok(copy, delim);
	while (token != NULL)
	{
		_strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, delim);
	}

	printf("%d tokens\n", num_token);

	tokens[num_token] = NULL;
	free(token);
	free(copy);
	return (tokens);
}

/**
 * exec - Execute the given command and arguments.
 * @command: The path to the program to be executed.
 * @arguments: An array of strings representing command-line arguments.
 * @env: An array of strings representing the execution env.
 *
 * This function creates a new process using fork.
 *
 * Return: 0 if the execution is successful; -1 in case of failure.
 */

int exec(const char *command, char *const arguments[], char *const env[])
{
	pid_t child_pid = fork();
	int status;

	if (command == NULL)
	{
		return (-1);
	}

	if (arguments == NULL)
	{
		return (-1);
	}

	if (child_pid == -1)
	{
		perror("Fork failed");
		return (-1);
	} else if (child_pid == 0)
	{
		execve(command, arguments, env);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/**
 * print_env - Print the environment variables to the standard output.
 * @arv: An array of strings (unused in this function).
 *
 * The function iterates through the environment variables and prints each one.
 */

void print_env(char **arv __attribute__ ((unused)))
{
	char **env;

	for (env = environ; *env; env++)
	{
		_print(*env);
		_printchar('\n');
	}
}
