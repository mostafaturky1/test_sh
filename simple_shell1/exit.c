#include "shell.h"

/* int pro_Exit(str_cmd *command)
{
    return (NULL);
}
 */

void contol_C(int sig_num)
{
	char *prompt = "\n($) ";

	if (sig_num == SIGINT)
	{
		_print(prompt);
	}
}
