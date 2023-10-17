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

/**
 * struct mybuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

int _printchar(char c);
void _print(char *str);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char **tokenize_command(char *str, const char *delim);
int exec(const char *command, char *const arguments[], char *const environment[]);
int execute(char *arguments[]);
void print_env(char **arv __attribute__ ((unused)));
void isExist(int command_length, char *command);
int run(void);
char *_getenv(const char *name);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void contol_C(int sig_num);
list_path *pathstrok(char *path);
char *any_Path(char *filename, list_path *head);
char *search_Path(char *name, char *sep, char *value);
list_path *end_node(list_path **head, char *str);
void free_Arguments(char **arv);
void free_linked(list_path *head);
void pro_Exit(char **arguments);
int _converter(char *str);
void(*isBuild(char **arv))(char **arv);

#endif
