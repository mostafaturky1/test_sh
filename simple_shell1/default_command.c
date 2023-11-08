#include "shell.h"

void default_command(str_cmd *command)
{
	printf("default command\n");
	printf("command %s\n", command->arg[0]);
    exec(command->executablePath, command->arg, environ);
} 



int exec(char *command, char *arguments[], char *const env[])
{
    int status;
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
		execve(command, arguments, env);
		exit(EXIT_FAILURE);
		
	} else if (child_pid > 0)
	{  
		wait(&status);
	}
	else
	{
		exit(1);
		
	}
	return status;
}
