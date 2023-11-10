#include "shell.h"


int run(int mode)
{
    str_cmd command;
    size_t line_count = 0;
    char **lines = NULL;
    size_t i;
    
    command.output_message = NULL;
   
  

    lines = _getlines(&line_count, mode);

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
        
        if(command.output_status == STATUS_FAILED){
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

    if (!isatty(STDIN_FILENO))
    {
        run(NON_INTERACTIVE);
        return (0);
    }

    signal(SIGINT, contol_C);
    while (1)
    {
        _print("($) ");
        if (run(INTERACTIVE))
        {
            break;
        }        
    }
    return (0);


}

