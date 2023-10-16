#ifndef SHELL_H
#define SHELL_H

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

extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;

int _printchar(char c);
void _print(char *str);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_getline(void);
char **tokenize_command(char *str, const char *delim);
int exec(const char *command, char *const arguments[], char *const environment[]);
int execute(char *arguments[]);
void print_env(void);
int isExist(int command_length);
int run(void);
void printExit(void);
int is_space_command(const char *comamnd);
char *_getenv(const char *name);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void contol_C(int sig_num);

#endif
