#include "shell.h"

int execute(char *arguments[])
{
    int exe = 0;
    char *temp, *path;
    list_path *head = NULL;
    void (*exist)(char **);

    if (!arguments || !arguments[0])
    {
		return (0);
    }
    temp = _getenv("PATH");
    head = pathstrok(temp);
    path =any_Path(arguments[0], head);
    exist = isBuild(arguments);
    if (exist)
    {
        exist(arguments);
        return (0);
    }

    else if (!path){
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
    char *command = NULL, **args = NULL;
    size_t command_size = 0;
    ssize_t command_length = 0;
    
    command_length = getline(&command, &command_size, stdin);    
    isExist(command_length, command);
    
    if (command_length > 0 && command[command_length] == '\n')
    {
        command[command_length] = '\0';
    }
    args = tokenize_command(command, " \n");
    exited = execute(args);
    free_Arguments(args);
    free(command);
    return exited;
}

void isExist(int command_length, char *command)
{
        (void)command;
    if (command_length == -1)
    {
        if (isatty(STDIN_FILENO))
		{
			_print("\n");
			free(command);
		}
		exit(0);
    }
}

