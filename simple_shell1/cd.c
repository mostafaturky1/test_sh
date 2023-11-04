#include "shell.h"

void cd_command(str_cmd *command)
{

    if (command->arg[1] == NULL) return;

    if (chdir(command->arg[1]) == -1) {
        command->output_status = -1;
        command->output_message = "No Such file or directory";
    }
}

