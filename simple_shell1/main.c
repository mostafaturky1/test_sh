#include "shell.h"

/**
 * isInteractiveMode - Check if the shell is in interactive mode
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */

int isInteractiveMode(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * run - Execute the commands in the given array of lines
 * @lines: Array of input lines
 * @line_count: Number of lines
 *
 * Return: Exit status
 */

int  run(char **lines, size_t line_count)
{
	str_cmd command;
	size_t i;
	int status = EXIT_SUCCESS;

	if (!lines)
	{
		return (-1);
	}

	for (i = 0; i < line_count; i++)
	{
		status = EXIT_SUCCESS;
		command.output_message = NULL;
		command.output_status = STATUS_SUCCESS;

		command.input = _strdup(lines[i]);
		Parser(&command);

		if (!command.arg || !command.arg[0])
		{
			command.executablePath = NULL;
			free_struct(&command);
			free(lines[i]);
			continue;
		} 
		if (_strcmp(command.arg[0], "exit") == 0)
		{
			free(lines[i]);
			free(lines);
			exit_command(&command);
		}
		execute(&command);
		if (command.output_status == STATUS_FAILED_FULL)
		{
			_printErr("./hsh: ");   /*  need to be hsh */
			_printIntErr(i + 1);
			_printErr(": ");
			_printErr(command.arg[0]);
			_printErr(": ");
			_printErr(command.output_message);
			_printErr("\n");
			status = _EXIT_FAILURE;
		}

		if (command.output_status == STATUS_FAILED_PARTIAL)
		{
			_printErr(command.arg[0]);
			_printErr(": ");
			_printErr(command.arg[1]);
			_printErr(": ");
			_printErr(command.output_message);
			_printErr("\n");
			status = _EXIT_FAILURE;
		}
		
		if (command.output_status == STATUS_ERROR){
			status = STATUS_ERROR;
		} 

		free_struct(&command);
		free(lines[i]); /*  Free individual lines */
	}
	free(lines); /*  Free the array of lines */
	return (status); /* Return status */
}

/**
 * main - Entry point of the shell program
 *
 * Return: Exit status
 */

int main(void)
{
	size_t line_count = 0;
	char **lines = NULL;
	int status = EXIT_SUCCESS;
	char **(*input_func)(size_t *) = _getAll;

	signal(SIGINT, contol_C);
	while (1)
	{
		if (isInteractiveMode())
		{
			_print("($) ");
			input_func = _getline;
		}

		lines = (*input_func)(&line_count);
		status = run(lines, line_count);

		if (status || !isInteractiveMode())
		{
			break;
		}
	}
	return (status);
}

