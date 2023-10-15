#include "shell.h"

int execute(char *arguments[], char *const environment[])
{
    int exe = 0;

    /* ls command execution*/
    if (_strcmp(arguments[0], "/bin/ls") == 0 || _strcmp(arguments[0], "ls") == 0)
    {
        exe = exec("/bin/ls",arguments,environment);
        if ( exe == -1) 
        {
           perror("execve");
        }
        free(arguments);
        return 0;
    }

    /* return if the command is empty*/
    if (_strcmp(arguments[0], "\n") == 0)
    {
        return 0;
    }
   
     if (_strlen(arguments[0]) == -1)
    {
        return 0;
    }
    
    /* if exit then end the application*/
    if (_strcmp(arguments[0], "exit") == 0) {
        return 1;
    }
    
    if (_strcmp(arguments[0], "env") == 0)
    {
        get_env();
        return 0;
    }
    
    _print("hsh: ");
    _print(arguments[0]);
    _print(" :command not found");
    _printchar('\n');
    
    return (0);
}

int run(void){
    char **args;
    int command_length;
    char *command = NULL; 
    int exited = 0;
    int num = 0;
    int j;

    command = _getline();
    command_length = _strlen(command) - 1;
    exited = isExist(command_length);
    if (exited)
    {
         /* free pointers*/
        free(command);
        return exited;
    }
        /*empty command*/
  /*  is_space_command(command);*/

    if (command_length > 0 && command[command_length] == '\n')
    {
        command[command_length] = '\0';
    }

    args = tokenize_command(command, &num);
    exited = execute(args, NULL);

    free(command);
    for (j = 0; j < num; j++) 
    {
        free(args[j]);
    }
    free(args);
    return exited;
}

int isExist(int command_length){

    if (command_length != -1)
    {
        return 0;
    }

    return 1;
}

int is_space_command(const char *comamnd) {
    int i;
    printf("%s", comamnd);
    for ( i = 0; comamnd[i] != '\0'; i++) {
        if (comamnd[i] != ' ') {
            return 1; /* Not a space command*/
        }
    }
    return 0; /* Consists only of space characters*/
}
