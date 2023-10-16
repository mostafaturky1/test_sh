#include "shell.h"

char **tokenize_command(const char *command, int *num_args) {
    char **args = NULL;
    char *token;
    char *temp = _strdup(command);
    int i = 0;
    int j;

    if (temp == NULL) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    token = strtok(temp, " ");
    *num_args = 0;

    while (token != NULL) {
        (*num_args)++;
        token = strtok(NULL, " ");
    }

    args = (char **)malloc((*num_args + 1) * sizeof(char *));
    if (args == NULL) {
        perror("malloc");
        free(temp);
        exit(EXIT_FAILURE);
    }

    /* Reset temp and token to the beginning of the command*/
    temp = _strdup(command);
    token = strtok(temp, " ");

    if (temp == NULL) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < *num_args; i++) {
        args[i] = _strdup(token);
        if (args[i] == NULL) {
            perror("strdup");
            for ( j = 0; j < i; j++) {
                free(args[j]);
            }
            free(args);
            free(temp);
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " ");
    }

    args[*num_args] = NULL;
    free(temp);  /* Free temp only once*/
    return args;
}


int exec(const char *command, char *const arguments[], char *const environment[]){
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Fork failed");
        return -1;
    } else if (child_pid == 0) {
        execve(command, arguments, environment);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        wait(&status);
    }
    return 0;
}

void get_env(void)
{
    extern char **environ;
    char** env;
    for (env = environ; *env; env++)
    {
        _print(*env);
        _printchar('\n');
    }
    _printchar('\n');
}
