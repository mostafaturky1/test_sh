#include "shell.h"

int execute(char *arguments[])
{
    int exe = 0;
    char *temp, *path;
    list_path *head = NULL;

    if (!arguments || !arguments[0])
		return (0);
    /* if exit then end the application*/
    if (_strcmp(arguments[0], "exit") == 0) {
        return 1;
    }
    
    if (_strcmp(arguments[0], "env") == 0)
    {
        print_env();
        return 0;
    }
    temp = _getenv("PATH");
    head = pathstrok(temp);
    path =any_Path(arguments[0], head);
    if (!path){
        exe = exec(arguments[0],arguments,environ);
        if ( exe == -1) 
        {
           perror(arguments[0]);
        }
        return 0;
    }
    else if (path){
        free(arguments[0]);
        arguments[0] = path;
        exe = exec(arguments[0],arguments,environ);
        if ( exe == -1) 
        {
           perror(arguments[0]);
        }
        return 0;
    }
    return (0);
}

int run(void){
    int  exited = 0;
    char *command = NULL, **args;
    size_t command_size = 0;
    ssize_t command_length;
    
    command_length = getline(&command, &command_size, stdin);    
    exited = isExist(command_length);
    if (exited)
    {
         /* free pointers*/
        free(command);
        return exited;
    }
        /*empty command*/
    if (command_length > 0 && command[command_length] == '\n')
    {
        command[command_length] = '\0';
    }
    args = tokenize_command(command, " \n");
    exited = execute(args);
    
    free(args);
    return exited;
}

int isExist(int command_length){

    if (command_length != -1)
    {
        _printchar('\n');
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
