#include "shell.h"

char* _getenv(const char* varname) {
    size_t varname_len;
    char** env;

    if (varname == NULL) {
        return NULL;
    }

    varname_len = _strlen(varname);
    for (env = environ; *env != NULL; env++) {
        if (_strncmp(*env, varname, varname_len) == 0 && (*env)[varname_len] == '=') {
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

    command->executablePath = NULL;
    if (path == NULL) {
        return NULL;
    }
    pathCopy = _strdup(path);
    token = _strtok(pathCopy, ":");

    while (token != NULL) {
        /*  Check if the executable file exists in the current directory */
        fullPath = (char*)malloc(_strlen(token) + 1 + _strlen(command->arg[0]) + 1);
        _strcpy(fullPath, token);
        _strcat(fullPath, "/");
        _strcat(fullPath, command->arg[0]);

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

void env_command(str_cmd *command)
{
    
    char **env_var = environ;
    command->output_message = NULL;
    command->output_status = 0;

    while (*env_var != NULL) {
        _print(*env_var);
        _print("\n");
        env_var++;
    }
}



int _unsetenv(const char *name) {
    char **current = environ;
    char **previous = NULL;

    if (name == NULL || name[0] == '\0')
        return -1;

    while (*current != NULL) {
        if (_strstr(*current, name) == *current) {
            /* Found the environment variable, remove it */
            if (previous == NULL) {
                /* Variable to be removed is at the beginning of the environment */
                environ++;
            } else {
                /* Variable to be removed is not at the beginning */
                *previous = *(current + 1); /* Shift the environment array */
            }
            /* Free the memory */
            free(*current);
            return 0;
        }
        previous = current;
        current++;
    }
    return -1; /* Variable not found */
}

void setenv_command(str_cmd *command) {
    int result;

    if (command->arg[2] == NULL || command->arg[3] == NULL) {
        command->output_message = "Usage: setenv VARIABLE VALUE";
        return;
    }
    result = _setenv(command->arg[2], command->arg[3]);
    if (result == -1) {
        command->output_message = "_setenv error";
    }
}

void unsetenv_command(str_cmd *command) {
    int result;
    
    if (command->arg[2] == NULL) {
        command->output_message = "Usage: unsetenv VARIABLE";
        return;
    }

    result = _unsetenv(command->arg[2]);
    if (result == -1) {
        command->output_message = "Variable not found";
    }
}

int _addenv(const char *name, const char *value) {
    int env_size = 0, i;
    char *new_var = NULL;
    
    while (environ[env_size] != NULL)
        env_size++;

    new_var = malloc(_strlen(name) + _strlen(value) + 2);
    if (!new_var) {
        perror("Error in _addenv");
        return -1;
    }
    _strcpy(new_var, name); /* Copy name to new_var */
    _strcpy(new_var + _strlen(name), "="); /* Concatenate "=" */
    _strcpy(new_var + _strlen(name) + 1, value); /*  Concatenate value */

    /* Shift existing variables to make room for the new one */
    for (i = env_size; i >= 0; i--) {
        environ[i + 1] = environ[i];
    }
    environ[0] = new_var;
/*     free(new_var);
 */    return 0;
}

int _setenv(char *name, char *value) {
    char *var;

   
    if (name == NULL || name[0] == '\0' || value == NULL)
        return -1;

    var = _getenv(name);

    if (var) {
            /* Variable exists, so we need to replace it */
            _unsetenv(name);
            _addenv(name, value);
    } else {
        /* Variable does not exist, so we create a new one */
        _addenv(name, value);
    }
    return 0;
}
