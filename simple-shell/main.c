#include "shell.h"

int main(void)
{
   int  exited = 0;
    char *command = NULL, **args = NULL;
    size_t command_size = 0;
    ssize_t command_length = 0;

    while (1)
    {
    if (isatty(STDIN_FILENO))
		_print("($) ");
        
    command_length = getline(&command, &command_size, stdin);    
    isExist(command_length, command);
    
    if (command_length > 0 && command[command_length] == '\n')
    {
        command[command_length] = '\0';
    }
    args = tokenize_command(command, " \n");
    exited = execute(args);
    }
    free_Arguments(args);
    free(command);
    return exited;
}






