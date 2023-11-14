#include "shell.h"

/**
 * default_command - Execute a command with default settings
 * @command: Pointer to the command structure
 *
 * Return: None
 * Updates command structure with output status and message if needed.
 */

void default_command(str_cmd *command)
{
	if (exec(command->executablePath, command->arg, environ))
	{
		command->output_status = STATUS_FAILED_PARTIAL;
		command->output_message = "No such file or directory";
	}
}

/**
 * exec - Execute a command with specified arguments and environment
 * @command: The command to execute
 * @arguments: Array of arguments including the command itself
 * @env: Array of environment variables
 *
 * Return: Exit status of the executed command
 * If an error occurs, -1 is returned.
 */

int exec(char *command, char *arguments[], char *const env[])
{
	int status, dev_null = open("/dev/null", O_WRONLY);
	pid_t child_pid;

	if (command == NULL)
	{
		return (-1);
	}
	if (arguments == NULL)
	{
		return (-1);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (dev_null == -1)
		{
			perror("Failed to open /dev/null");
			exit(EXIT_FAILURE);
		}
		if (dup2(dev_null, STDERR_FILENO) == -1)
		{
			perror("Failed to redirect stderr");
			exit(EXIT_FAILURE);
		}
		status = execve(command, arguments, env);
		if (status == -1)
		{
			errno = 0;
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid > 0)
	{
		wait(&status);
	}
	else
	{
		exit(1);
	}
	return (status);
}
