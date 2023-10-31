#ifndef CD_H
#define CD_H

#include <stdio.h>
#include "../command.h"


/*
To Do: cd_command(command struct)
takes: pointer to struct of type command
return: pointer to struct of type output
*/

char cd_command(str_cmd *command);

#endif