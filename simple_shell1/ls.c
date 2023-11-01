#include "shell.h"

void ls_command(str_cmd *command)
{
    exec(_strcat("/usr/bin/", command->arg[0]), command->arg, NULL);
} 
