#include "shell.h"

int main(void)
{
    char *prompt = "($) ";
    
    
    /* if echo run the command once*/
    if (!isatty(STDIN_FILENO)){
        run();
        return 0;
    }
    signal(SIGINT, contol_C);
    /* run the application loop*/
    while (1)
    {
        _print(prompt);
       if(run())
       {
         break;
       }
        
    }
   
    return 0;
}





