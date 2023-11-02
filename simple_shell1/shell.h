#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define DELIM_COMMAND " "
#define DELIM_PATH ";"

extern char *const *environ;


typedef struct {
    size_t size;
} SizeInfo;

/* data.c */
typedef struct data {

    char *input; /* from get line */
    size_t input_length; /* length of the input */
    char **arg;

    /* the output of the command */
    char *output_message;
    int output_status;

} str_cmd;

/*
To DO: Declare a static variable called **location** to store the last location of my shell char*
-- the initial location could be the current file location 

*/

/*
To Do: create static PATH variables to load the pathes inside it in a char ** when the application initialized

*/

/* cd.c */

/*
To Do: cd_command(command struct)
takes: pointer to struct of type command
return: pointer to struct of type output
*/

/* char cd_command(str_cmd *command);
 */
/* echo.c */
/* int echo_command(str_cmd *command);
 */
/* env.c */
/* void env_commmand(str_cmd *command);
 */
/* executer.c */
int run(void);


/*
To Do: command_clean() to free any static variable if exist

*/

/* exit.c */
/* int pro_Exit(str_cmd *command);
 */
void contol_C(int sig_num);
/* ls.c */
void ls_command(str_cmd *command);

/* sting.c */
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *destination, const char *source);
int _printchar(char c);
void _print(char *str);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *str, int ch);
char* _strdup(const char* str);

/* getline.c */
str_cmd _getline(void);

/* parser.c */
void Parser(str_cmd *command);

/* memory.c */
void *_realloc(void *ptr, size_t size);
void free_struct(str_cmd command);
void* _memmove(void* dest, const void* src, size_t n);


int exec(char *command, char *arguments[], char *const env[]);
void execute(str_cmd *command);

#endif
