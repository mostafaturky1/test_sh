#include "shell.h"


void execute(str_cmd *command){
    int status = -1;


   status =  exec(_strcat("/usr/bin/", command->arg[0]), command->arg, environ);
	
	if(status == -1){
        command->output_message = "hsh: command not found: ";
        command->output_status = -1;
        printf("error %d", status);
	}

}




int exec(const char *command, char *const arguments[], char *const env[])
{

    int status;
    pid_t child_pid = fork();

    printf("command: %s\n", command);
    printf("arg[0]: %s\n", arguments[0]);
    printf("env: %s\n", env[0]);
	
	

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
        printf("executing ................\n");
		execve(command, arguments, env);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
