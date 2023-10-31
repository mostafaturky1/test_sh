#include "shell.h"

int run(void)
{
    int i = 0;
    str_cmd command;


    command = _getline();
    command = splitCommand(command, " ");
    printf("iput: %s\n", command.input);
    while (command.arg[i]){
    printf("arg %d: %s\n", i, command.arg[i]);
    i++;
    }
    free_struct(command);    
    return (0);
}
