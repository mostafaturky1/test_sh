#include "shell.h"

void execute(char *arguments[])
{
    int exe = 0;
    char *temp = NULL, *path = NULL;
    list_path *head = NULL;
    void (*exist)(char **);

    if (!arguments || !arguments[0])
    {
		return;
    }
    temp = _getenv("PATH");
    head = pathstrok(temp);
    path =any_Path(arguments[0], head);
    exist = isBuild(arguments);
    if (exist)
    {
        exist(arguments);
        return;
    }

    else if (!path){
        exe = exec(arguments[0],arguments,environ);
        if ( exe == -1) 
        {
           perror(arguments[0]);
        }
        return;
    }
    else if (path){
        free(arguments[0]);
        arguments[0] = path;
        exe = exec(arguments[0],arguments,environ);
        if ( exe == -1) 
        {
           perror(arguments[0]);
        }
        free(path);
        return ;
    }
    return;
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

