#include "shell.h"
#include <string.h>

void execute(str_cmd *command){
    
    void (*command_executor) (str_cmd*) = default_command;

    findExecutablePath(command);
    if(_strcmp(command->arg[0], "exit") == 0)
    {
        command_executor= exit_command;
    }
    if(_strcmp(command->arg[0], "env") == 0)
    {   if (command->arg[1])
        {
            if(_strcmp(command->arg[1], "setenv") == 0)
            {
            command_executor= setenv_command;
            }
            else if(_strcmp(command->arg[1], "unsetenv") == 0)
            {
                command_executor= unsetenv_command;
            }    
            else
            {
                command_executor= env_command;
            }
        }
    }
     
    if(_strcmp(command->arg[0], "cd") == 0)
    {
        command_executor= cd_command;
    }
    if(_strchr(command->arg[0], '/') != NULL)
    {
        command->executablePath = _strdup(command->arg[0]);
    }
    command->output_status = STATUS_SUCCESS;
    if(command_executor == default_command && command->executablePath == NULL){
            command->output_message = _strcat("hsh: ", command->arg[0]);
            command->output_message = _strcat(command->output_message, ": not found");
            command->output_status = STATUS_FAILED;
            return;
    }
    (*command_executor)(command);
}

