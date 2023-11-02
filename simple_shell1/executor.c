#include "shell.h"

void execute(str_cmd *command){
    int status = -1;
    char *filePath;

    filePath = _strcat("/bin/", command->arg[0]);
   status =  exec(filePath, command->arg, environ);
	
	if(status == -1){
        command->output_message = "hsh: command not found: ";
        command->output_status = -1;
	}
    free(filePath);
}

int exec(const char *command, char *const arguments[], char *const env[])
{
    int status;
    pid_t child_pid = fork();

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
