#include "shell.h"


int isInteractiveMode(void){
	return isatty(STDIN_FILENO);
}

int run(char **lines, size_t line_count)
{
    str_cmd command;
    size_t i;

    command.output_message = NULL;

    if (!lines) {
        return -1;
    }


    for (i = 0; i < line_count; i++) {
        
        command.input = _strdup(lines[i]);

        Parser(&command);
       

        if(!command.arg || !command.arg[0]){
            command.executablePath = NULL;
            free_struct(&command);
            free(lines[i]); 
            continue;
        }


        execute(&command);
        
        if(command.output_status == STATUS_FAILED_FULL){
            _print("./hsh: ");   /* need to be hsh */
            _printInt(i+1);
            _print(": ");
            _print(command.arg[0]);
            _print(": ");
            _print(command.output_message);
            _print("\n");
        
        }

        if(command.output_status == STATUS_FAILED_PARTIAL){
            _print(getCommand(command.arg[0]));
            _print(": ");
            _print(command.arg[1]);
            _print(": ");
            _print(command.output_message);
            _print("\n");
        
        }
        
        free_struct(&command);
        free(lines[i]); /*  Free individual lines */
    }

    
    free(lines); /*  Free the array of lines */
    return (0);
}


/*
main function

// outside the application loop, load the paths env variable and initialize the current location variable

contain application loop that calls one function which is the run()

*/
int main(void)
{
	size_t line_count = 0;
    char **lines = NULL;
	int status = 1;
	char **(*input_func)(size_t*) = _getAll;
   
    signal(SIGINT, contol_C);

    while (1)
    {
		if(isInteractiveMode()){
		    _print("($) ");
            input_func = _getline;
		}

		lines = (*input_func)(&line_count);
       	status = run(lines, line_count);

        if (status || !isInteractiveMode())
        {
            break;
        }        
    }
    return (0);


}

