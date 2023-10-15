#include "shell.h"

char *_getline(void)
{
    char *command = NULL;
    size_t command_size = 0;

    getline(&command, &command_size, stdin);
    return (command);
}
