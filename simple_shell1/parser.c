#include "shell.h"

str_cmd splitCommand(str_cmd command, const char* delim) { 
    int argCount = 0;
    char* token = _strtok(command.input, delim);
    
    command.arg = NULL;
    while (token != NULL) {
        command.arg = (char**)_realloc(command.arg, (argCount + 1) * sizeof(char*));
        if (command.arg == NULL) {
            perror("Memory allocation error");
            exit(1);
        }

        command.arg[argCount] = _strdup(token);
        if (command.arg[argCount] == NULL) {
            perror("Memory allocation error");
            exit(1);
        }

        argCount++;
        token = _strtok(NULL, delim);
    }

    command.arg = (char**)_realloc(command.arg, (argCount + 1) * sizeof(char*));
    if (command.arg == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    command.arg[argCount] = NULL;  /* Null-terminate the arguments list */

    return (command);
}
