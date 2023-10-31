#include "shell.h"

/**
 * getExecutablePaths - Retrieves executable paths from the PATH environment.
 *
 * This function extracts executable paths from the PATH environment variable,
 * splits them using ':' as a delimiter, and returns an array of paths.
 *
 * Return: An array of executable paths or NULL if PATH is not set.
 */

char **getExecutablePaths(void)
{
	char **paths = NULL;

	char *path = _getenv("PATH");
	printf("***path: %s\n", path);

	if (path == NULL)
	{
		return (NULL);
	}

	paths = tokenize(path, ":");

	printf("***path: %s\n", path);

	free(path);
	return (paths);
}

/**
 * append - Appends a new path part to an existing path.
 * @existingPath: The original path.
 * @newPathPart: The new path part to append.
 *
 * This function appends a new path part to an existing path, ensuring
 * the resulting path is properly formatted with a '/' separator.
 *
 * Return: A new string representing the combined path, or NULL on failure.
 */

char *append(char *existingPath, char *newPathPart)
{
	size_t existingLen;
	size_t newLen;
	size_t totalLen;
	char *newPath = NULL;

	if (existingPath == NULL)
	{
		return (_strdup(newPathPart));
	}
	existingLen = _strlen(existingPath);
	newLen = _strlen(newPathPart);

	totalLen = existingLen + newLen + 2;

	newPath = (char *)malloc(totalLen);

	if (newPath == NULL)
	{
		return (NULL);
	}

	_strcpy(newPath, existingPath);

	if (existingPath[existingLen - 1] != '/')
	{
		_strcat(newPath, "/");
	}

	_strcat(newPath, newPathPart);

	return (newPath);
}

/**
 * execute - Execute a command with given arguments.
 * @tokens: An array of strings representing the command and its arguments.
 * Return: 0 if the command is executed successfully, otherwise 0.
 */

int execute(char *tokens[])
{
	char **executablePaths = NULL;
	char *filePath = NULL;
	int status = -1;
	int i;

	if (!tokens || !tokens[0])
	{
		if (isatty(STDIN_FILENO))
		{
			_print("\n");
		}

		return (0);
	}

	printf("getting paths\n");
	executablePaths = getExecutablePaths();
	
	printf("Paths done\n");
    if (!executablePaths) {
        return (-1);
    } 

	for (i = 0; executablePaths[i] != NULL; i++) {
           
		filePath = append(executablePaths[i], tokens[0]);

		printf("Path: %s\n", filePath);
		status = exec(filePath, tokens, environ);

		free(executablePaths[i]);
		free(filePath);
	}
        
	free(executablePaths);
	
	if(status){
		_print("hsh: command not found: ");
		_print(tokens[0]);
		_print("\n");
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

	printf("Getting Input line\n");
	line_size = getline(&line, &line_size, stdin);
	if (!isExist(line_size, line))
	{
		if(line) free(line);
		return (1);
	}
	if (length > 0 && line[line_size] == '\n')
	{
		line[line_size] = '\0';
	}
	printf("Input line %s\n", line);

	tokens = tokenize(line, " \n");

	printf("Tokens %s\n", tokens[0]);
	exited = execute(tokens);

	printf("Execution Done\n");
	if(line) free(line);
	return (exited);
}

