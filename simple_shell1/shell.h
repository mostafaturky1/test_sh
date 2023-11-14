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
#define STATUS_FAILED_FULL  -1
#define STATUS_FAILED_PARTIAL  -2
#define STATUS_ERROR  2
#define STATUS_SUCCESS  1

#define	_EXIT_FAILURE	127
#define	_EXIT_SUCCESS	0

#define INTERACTIVE 1
#define NON_INTERACTIVE 0

extern char **environ;

/**
 * struct data - Structure representing a shell command
 * @input: Pointer to the input string obtained from getline
 * @input_length: Length of the input string
 * @arg: Array of strings representing command arguments
 * @executablePath: Path to the executable associated with the command
 * @output_message: Output message generated by the command
 * @output_status: Status code indicating the success or failure of the command
 *
 * Description: This structure is used to store information
 * related to a shell command, including the input string,
 * command arguments, executable path, output message, and status.
 */

typedef struct data
{
	char *input; /* from get line */
	size_t input_length; /* length of the input */
	char **arg;
	char *executablePath;
	/* the output of the command */
	char *output_message;
	int output_status;

} str_cmd;


/* cd.c */
void cd_command(str_cmd *);


/* exit.c */
void exit_command(str_cmd *command);
void contol_C(int sig_num);

/* default_command.c */
void default_command(str_cmd *command);

/* sting.c */
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *destination, const char *source);
int _printchar(char c);
int _printInt(size_t c);
int _printIntErr(size_t c);
void _print(char *str);
void _printErr(char *str);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *str, int ch);
char *_strrchr(const char *str, int character);
char *_strdup(const char *str);
char *getCommand(const char *path);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strstr(const char *haystack, const char *needle);
char *_strncpy(char *dest, const char *src, size_t n);
int _printcharFile(FILE *stream, char c);

/* getline.c */
char **_getAll(size_t *line_count);
char **_getline(size_t *line_count);
char *getCommand(const char *path);
char **splitLines(const char *input, size_t *lineCount);
char *readLine(void);
char *readAll(void);
int _isspace(char c);
void finalizeLines(char **lines, size_t *lineCount, const char *input);
char *trimSpaces(const char *input);

/* env.c */
char *_getenv(const char *varname);
void *findExecutablePath(str_cmd *command);
void env_command(str_cmd *command);
int _setenv(char *name,  char *value);
int _unsetenv(const char *name);
void unsetenv_command(str_cmd *command);
void setenv_command(str_cmd *command);
int _addenv(const char *name, const char *value);

/* parser.c */
void Parser(str_cmd *command);

/* memory.c */
void *_realloc(void *ptr, size_t size);
void free_struct(str_cmd *command);
void *_memmove(void *dest, const void *src, size_t n);
void *_realloc2(void *ptr, size_t old_size, size_t new_size);
void *_memcpy(void *dest, const void *src, size_t n);


int exec(char *command, char *arguments[], char *const env[]);
void execute(str_cmd *command);

#endif

