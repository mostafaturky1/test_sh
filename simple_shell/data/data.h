#include <stdio.h>

typedef struct str_cmd {

    char *input = NULL; // from get line
    char **args = NULL;

    // the output of the command
    char *output_message = NULL;
    int *output_status = 0;

} command;


/*
To DO: Declare a static variable called **location** to store the last location of my shell char*
-- the initial location could be the current file location 

*/

/*
To Do: create static PATH variables to load the pathes inside it in a char ** when the application initialized

*/