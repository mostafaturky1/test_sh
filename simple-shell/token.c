#include "shell.h"

/**
 * tokenize_command - Tokenize a string using a specified delimiter.
 * @str: The string to be tokenized.
 * @delim: The delimiter used to split the string.
 *
 * Return: it return array of string
 */

char **tokenize(char *line, const char *delim)
{
	int num_token = 0;
	int i = 0;
	int j = 0;
	char **tokens = NULL;
	char *token = NULL;
	int maxTokenLength = 0;
	char *copy = NULL;

	if (line == NULL || delim == NULL) return NULL;

	copy = malloc(_strlen(line) + 1);

	if (copy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}

	_strcpy(copy, line);

	token = strtok(copy, delim);
	while(token != NULL){
	
		num_token++;	
		if(_strlen(token) > maxTokenLength) maxTokenLength = _strlen(token);

		token = strtok(NULL, delim);

	}

	tokens = (char **)malloc(num_token * sizeof(char *));
	for (j = 0; j < num_token; j++) {
        tokens[j] = (char *)malloc((maxTokenLength + 1) * sizeof(char));
    }

	token = strtok(copy, delim);
    while (token != NULL)
	{
        _strcpy(tokens[i], token);
        i++;
        token = strtok(NULL, delim);
		
    }



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
	if (command == NULL){
		return (-1);
	}

	if (arguments == NULL){
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

/**
 * _realloc - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}
