#include "shell.h"

int execute(char *arguments[], char *const environment[])
{
    int i = 0;
    int exe = 0;

    // ls command execution
    if (_strcmp(arguments[0], "/bin/ls") == 0 || _strcmp(arguments[0], "ls") == 0)
    {
        exe = exec("/bin/ls",arguments,environment);
        if ( exe == -1) 
        {
           perror("execve");
        }

        return 0;
    }

    // return if the command is empty
    //for (i = 0;arguments[i]; i++){
    if (_strcmp(arguments[i], "\n") == 0)
    {
        return 0;
    }
   // }
     if (_strlen(arguments[0]) == -1)
    {
        return 0;
    }
    
    // if exit then end the application
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
    char *command; 
    int exited = 0;
    int num = 0;

    command = _getline();
    command_length = _strlen(command) - 1;
    exited = isExist(command_length);
    if (exited)
    {
         // free pointers
        free(command);
        return exited;
    }
        //empty command
  //  is_space_command(command);

    if (command_length > 0 && command[command_length] == '\n')
    {
        command[command_length] = '\0';
    }

    // break down commands 
    args = tokenize_command(command, &num);

    

    // run checker
    exited = execute(args, NULL);

    // free pointers
    free(command);
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
            return 1; // Not a space command
        }
    }
    return 0; // Consists only of space characters
}
