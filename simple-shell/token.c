#include "shell.h"

char **tokenize_command(const char *command, int *num_args) {
    char **args = NULL;
    char *token;
    char *temp = _strdup(command);
    int i = 0;
    int j = 0;

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

     token = strtok(_strdup(command), " ");
    for (; i < *num_args; i++) {
        args[i] = _strdup(token);
        if (args[i] == NULL) {
            perror("strdup");
            free(temp);
            for (; j < i; j++) {
                free(args[j]);
            }
            free(args);
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " ");
    }

    args[*num_args] = NULL;
    free(token);
    free(temp);
    free(_strdup(command));
    free(_strdup(token));
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
        free(arguments);
        exit(EXIT_FAILURE);
    } else {
        int status;
        wait(&status);
    }
    free(arguments);
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
