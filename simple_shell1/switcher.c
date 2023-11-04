#include "shell.h"

/* int echo_command(str_cmd *command)
{
    return (NULL);
} */

void switcher(str_cmd *command)
{
    if(_strcmp(command->arg[0], "exit") == 0)
    {
        command->executablePath = 0;

        exitProgram(*command);
    }
    if(_strchr(command->arg[0], '/') != NULL)
    {
        command->executablePath = 0;

        exec(command->arg[0],command->arg,environ);
        return;
    }
    findExecutablePath(command);
    execute(command);
}
