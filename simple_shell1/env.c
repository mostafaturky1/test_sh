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

char* findExecutablePath(const char* command) {
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
        fullPath = (char*)malloc(strlen(token) + 1 + strlen(command) + 1);
        _strcpy(fullPath, token);
        strcat(fullPath, "/");
        strcat(fullPath, command);

        if (access(fullPath, X_OK) == 0) {
            free(pathCopy);
            return fullPath;
        }

        free(fullPath);
        token = _strtok(NULL, ":");
    }

    free(pathCopy);
    return NULL;
}


/* void env_commmand(str_cmd *command)
{
    return (NULL);
} */
