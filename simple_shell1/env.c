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

void env_command(void)
{
    char** env;
    for (env = environ; *env; env++)
    {
        _print(*env);
        _printchar('\n');
    }
}

int _setenv(const char *name, const char *value, int overwrite) {
    char *var, *new_var = NULL;

    if (name == NULL || name[0] == '\0' || value == NULL)
        return -1;

    var = _getenv(name);

    if (var) {
        if (overwrite) {
            
            int index = var - environ[0]; 
            free(var);
            new_var = malloc(_strlen(name) + _strlen(value) + 2);
            if (!new_var) {
                perror("Error in _setenv");
                return -1;
            }
            _strcpy(new_var, name); 
            _strcpy(new_var + _strlen(name), "="); 
            _strcpy(new_var + _strlen(name) + 1, value); 
            environ[index] = new_var;
        }
    } else {
        int env_size = 0;
        while (environ[env_size] != NULL)
            env_size++;
        new_var = malloc(_strlen(name) + _strlen(value) + 2);
        if (!new_var) {
            perror("Error in _setenv");
/*             free(new_var);
 */            return -1;
        }
        _strcpy(new_var, name); 
        _strcpy(new_var + _strlen(name), "="); 
        _strcpy(new_var + _strlen(name) + 1, value); 
        environ[env_size] = new_var;
        environ[env_size + 1] = NULL; 
    }
/*     free(new_var);
 */    return 0;
}

int _unsetenv(const char *name) {
    char **current = environ;
    char **previous = NULL;

    if (name == NULL || name[0] == '\0')
        return -1;

    while (*current != NULL) {
        if (strstr(*current, name) == *current) {
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
    int overwrite, result;

    if (command->arg[1] == NULL || command->arg[2] == NULL) {
        command->output_message = "Usage: setenv VARIABLE VALUE";
        return;
    }

    overwrite = 1;
    if (strcmp(command->arg[1], "0") == 0) {
        overwrite = 0;
    }

    result = _setenv(command->arg[1], command->arg[2], overwrite);
    if (result == -1) {
        command->output_message = "_setenv error";
    }
}

void unsetenv_command(str_cmd *command) {
    int result;
    
    if (command->arg[1] == NULL) {
        command->output_message = "Usage: unsetenv VARIABLE";
        return;
    }

    result = _unsetenv(command->arg[1]);
    if (result == -1) {
        command->output_message = "Variable not found";
    }
}
