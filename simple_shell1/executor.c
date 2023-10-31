#include "shell.h"

int run(void)
{
    int i = 0;
    str_cmd command;


    command = _getline();
    command = splitCommand(command, " ");
    while (command.arg[i]){
    printf("%s\n", command.arg[i]);
    i++;
    }
    free_struct(command);    
    return (0);
}
