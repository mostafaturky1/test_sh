#include "shell.h"

void default_command(str_cmd *command)
{
    if(exec(command->executablePath, command->arg, environ)){
		command->output_status = STATUS_FAILED_PARTIAL;
		command->output_message = "No such file or directory";
	}
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

		int dev_null = open("/dev/null", O_WRONLY);
        if (dev_null == -1) {
            perror("Failed to open /dev/null");
            exit(EXIT_FAILURE);
        }
        if (dup2(dev_null, STDERR_FILENO) == -1) {
            perror("Failed to redirect stderr");
            exit(EXIT_FAILURE);
        }
		
		status = execve(command, arguments, env);
		if (status == -1) {
    		errno = 0;
		}
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
