#include "shell.h"

int main(void)
{
    char *prompt = "($) ";
    
    /* if echo run the command once*/
    if (!isatty(STDIN_FILENO)){
        run();
        free;
        return 0;
    }

    /* run the application loop*/
    while (1)
    {
        _print(prompt);
       if(run())
       {
        free;
         break;
       }
        
    }
   
   printExit();
   free;
    return 0;
}





