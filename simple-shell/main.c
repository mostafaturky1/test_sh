#include "shell.h"

/**
 * main - Entry point for a command-line interpreter program.
 * The main function serves as the central control point for shell
 *
 * Return: Always returns 0 to indicate successful execution.
 */


int main(void)
{
	char *command = NULL, **args;
	size_t command_size = 0;
	ssize_t command_length = 0;
    list_path *head = NULL;

    while (1)
	{
	if (isatty(STDIN_FILENO))
    {
    _print("($) ");
    }
    signal(SIGINT, contol_C);
	command_length = getline(&command, &command_size, stdin);
	isExist(command_length, command);
	if (command_length > 0 && command[command_length] == '\n')
	{
		command[command_length] = '\0';
	}
    args = NULL;
	args = tokenize_command(command, " \n");
    head = execute(args);
    free_linked(head);
    }
    free_Arguments(args);
	
    free(command);
	return (0);
}
