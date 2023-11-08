#include "shell.h"



/*

Run Function *****

// declare the command from Command struct

// call parser(command)

// call executor(command)

// call print(command)

// function to free the command struct

*/

int run(void)
{
    str_cmd command;
    size_t len = 0;
    
    command.output_message = NULL;
   
/*     input = _getline();
 */ while (getline(&command.input,&len,stdin) != -1)
    {
        printf("input: %s", command.input);
        Parser(&command);
        printf("args: %s\n", command.arg[0]);
        if(!command.arg || !command.arg[0]){
            command.executablePath = NULL;
            free_struct(&command);
            return (0);
        }
            execute(&command);
        if(command.output_status == STATUS_FAILED){
            _print(command.output_message);
            _print("\n");
        }
    }
    free_struct(&command);
    return (0);
}


/*
main function

// outside the application loop, load the paths env variable and initialize the current location variable

contain application loop that calls one function which is the run()

*/
int main(void)
{
    int i = 0;

	if (!isatty(STDIN_FILENO))
	{
		if (run())
			_print("\n");
		return (0);
	}

	signal(SIGINT, contol_C);
	while (1)
	{
		_print("($) ");
		if (run())
		{
			break;
		}        
	}
    while (environ[i] != NULL)
        {
            free(environ[i]);
            i++;
        }
    return (0);


}
