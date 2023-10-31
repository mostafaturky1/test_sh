#include "shell.h"

int main(void)
{
	/* if echo run the command once*/
	if (!isatty(STDIN_FILENO))
	{
		if (run())
			_print("\n");
		return (0);
	}

	signal(SIGINT, contol_C);
	/* run the application loop*/
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


/*

Run Function *****

// declare the command from Command struct

// call parser(command)

// call executor(command)

// call print(command)

// function to free the command struct

*/


/*
main function

// outside the application loop, load the paths env variable and initialize the current location variable

contain application loop that calls one function which is the run()

*/
