#include "shell.h"

void execute(str_cmd *command){
    int status = -1;

    command->arg[0] = _strcat("/bin/", command->arg[0]);
    status =  exec(command->arg[0], command->arg, environ);
	
	if(status != 0){
        command->output_message = "hsh: command not found: ";
        command->output_status = -1;
	}

    if(status == -1){
        command->output_message = "hsh: somthing went wrong";
        command->output_status = -1;
        printf("error %d", status);
	}

}


int exec(char *command, char *arguments[], char *const env[])
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
    
	return status;
}
