#include "shell.h"
#include <string.h>

void execute(str_cmd *command){
    
    void (*command_executor) (str_cmd*) = default_command;
    command->output_status = STATUS_SUCCESS;

    findExecutablePath(command);

    if(_strcmp(command->arg[0], "exit") == 0)
    {
        command_executor= exit_command;
    }
    if(_strcmp(command->arg[0], "cd") == 0)
    {
        command_executor= cd_command;

    }
    if(_strchr(command->arg[0], '/') != NULL)
    {   
        command->executablePath = _strdup(command->arg[0]);
    }

    if(command_executor == default_command && command->executablePath == NULL){
            command->output_message = "not found";
            command->output_status = STATUS_FAILED_FULL;
            return;
    }

    if (command_executor == default_command && access(command->executablePath, X_OK) != 0) 
    {
        command->output_message = "not found";
        command->output_status = STATUS_FAILED_FULL;
        return;
    }

    (*command_executor)(command);
    
}


