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
	command.output_message = NULL;
    command.output_status = 0;

    command = _getline();
    Parser(&command);

	execute(&command);

	/* if(command.output_status == -1){
		_print(command.output_message);
		_print("\n");
	} */


	free_struct(command);    
    return (0);
}




/*
main function

// outside the application loop, load the paths env variable and initialize the current location variable

contain application loop that calls one function which is the run()

*/
int main(void)
{
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
    return (0);
}
