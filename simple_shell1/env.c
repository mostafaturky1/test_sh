#include "shell.h"

char* _getenv(const char* varname) {
    size_t varname_len;
    char** env;

    if (varname == NULL) {
        return NULL;
    }

    varname_len = strlen(varname);

    for (env = environ; *env != NULL; env++) {
        if (strncmp(*env, varname, varname_len) == 0 && (*env)[varname_len] == '=') {
            return &(*env)[varname_len + 1]; /*  Return the value part of the environment variable */
        }
    }

    return NULL; /*  Variable not found in the environment */
}

void* findExecutablePath(str_cmd* command) {
    char* path = _getenv("PATH");
    char* pathCopy;
    char* token;
    char* fullPath;

    if (path == NULL) {
        return NULL;
    }

    pathCopy = _strdup(path);
    token = _strtok(pathCopy, ":");

    while (token != NULL) {
        /*  Check if the executable file exists in the current directory */
        fullPath = (char*)malloc(strlen(token) + 1 + strlen(command->arg[0]) + 1);
        _strcpy(fullPath, token);
        strcat(fullPath, "/");
        strcat(fullPath, command->arg[0]);

        if (access(fullPath, X_OK) == 0) {
            command->executablePath = _strdup(fullPath);
            free(fullPath);
            free(pathCopy);
            return (command);
        }

        free(fullPath);
        token = _strtok(NULL, ":");
    }
    free(pathCopy);
    command->executablePath = NULL;
    return (NULL);
}

void print_env(void)
{
    char** env;
    for (env = environ; *env; env++)
    {
        _print(*env);
        _printchar('\n');
    }
}
/* void env_commmand(str_cmd *command)
{
    return (NULL);
} */
