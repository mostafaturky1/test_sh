#include "shell.h"

/**
 * execute - Execute a command with given arguments.
 * @arguments: An array of strings representing the command and its arguments.
 *
 * This function to executing a command with the specified arguments.
 *
 * Return: Always returns 0.
 */

// Function to split a string into an array of strings based on a delimiter
char** splitString(char* input, char* delimiter, int* count) {
    char* copy = _strdup(input);
    char* token = strtok(copy, delimiter);
    char** tokens = NULL;
    *count = 0;

    while (token) {
        (*count)++;
        tokens = (char**)realloc(tokens, sizeof(char*) * (*count));
        tokens[*count - 1] = _strdup(token);
        token = strtok(NULL, delimiter);
    }

    free(copy);
    return tokens;
}

// Function to get the paths from the PATH environment variable
char** getExecutablePaths(void) {

	int count;
	char** paths = NULL;

    char* path = _getenv("PATH");
    if (path == NULL) {
        return NULL; // PATH environment variable is not set
    }

    
    paths = splitString(path, ":", &count);

    return paths;
}

// Function to append a new part to an existing path
char* append(char* existingPath, char* newPathPart) {
	size_t existingLen;
	size_t newLen;
	size_t totalLen;
	char* newPath = NULL;


    if (existingPath == NULL) {
        return _strdup(newPathPart); // If the existing path is NULL, simply return the new part
    }

    existingLen = _strlen(existingPath);
    newLen = _strlen(newPathPart);
	

    // Calculate the length needed for the new path
    totalLen = existingLen + newLen + 2; // +1 for the separator and +1 for the null terminator

    // Allocate memory for the new path
    newPath = (char*)malloc(totalLen);

    if (newPath == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Copy the existing path to the new path
    _strcpy(newPath, existingPath);

    // Add a separator if necessary
    if (existingPath[existingLen - 1] != '/') {
        _strcat(newPath, "/");
    }

    // Append the new part
    _strcat(newPath, newPathPart);

    return newPath;
}

int execute(char *tokens[])
{
	char** executablePaths = NULL;
	int status = -1;

	_print("execute");

	if (!tokens || !tokens[0])
	{
		if (isatty(STDIN_FILENO))
		{
			_print("\n");
		}

		return (0);
	}


	executablePaths = getExecutablePaths();

    if (executablePaths) {
        int i;
        for (i = 0; executablePaths[i] != NULL; i++) {
           
			 executablePaths[i] = append(executablePaths[i], "/");
			 executablePaths[i] = append(executablePaths[i], tokens[0]);
			

			status = exec(executablePaths[i], tokens, environ);

            free(executablePaths[i]);
        }
        free(executablePaths);
    } 
	
	if(status){
        //printf("PATH environment variable is not set.\n");
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

	line_size = getline(&line, &line_size, stdin);
	
	if (!isExist(line_size, line)){
		free(line);
		return 1;
	}

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
