#include "shell.h"

/**
 * main - Entry point for a command-line interpreter program.
 * The main function serves as the central control point for shell
 *
 * Return: Always returns 0 to indicate successful execution.
 */

int main(void)
{
	char *prompt = "($) ";

	/* if echo run the command once*/
	if (!isatty(STDIN_FILENO))
	{
		if (run())
			_print("\n");
		return (0);
	}

	signal(SIGINT, contol_C);
	/* run the application loop*/
	while (1)
	{	
		printf("Application Loop\n");
		_print(prompt);
		if (run())
		{
			break;
		}

		printf("End Application Loop\ns");
	}
	return (0);
}

/**
 * isExist - Checks if a command exists and has a valid length.
 * @command_length: Length of the command input.
 * @command: The command input itself.
 *
 * Return: 1 if valid, 0 otherwise.
 */

int isExist(int command_length, char *command)
{
	if (command == NULL)
	return (0);

	if (command_length == -1)
	return (0);

	return (1);
}
