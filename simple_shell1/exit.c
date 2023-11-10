#include "shell.h"

/* int pro_Exit(str_cmd *command)
{
    return (NULL);
}
 */

void exit_command(str_cmd *command) {
   if (command->arg[1]) {
        /* Parse the argument as an integer */
        int status = atoi(command->arg[1]);
        /* Exit the shell with the specified status */
        free_struct(command);
        exit(status);
    } else {
        /* No argument provided, exit with status 0 */
        free_struct(command);
        exit(0); 
    }
}

void contol_C(int sig_num)
{
	char *prompt = "\n($)";

	if (sig_num == SIGINT)
	{
		_print(prompt);
	}
}
