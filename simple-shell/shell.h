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

/* string2.c */
int _printchar(char c);

/* string2.c */
void _print(char *str);

/* string.c */
char *_strdup(char *str);

/* string.c */
char *_strcpy(char *dest, char *src);

/* string.c */
int _strlen(char *s);

/* string.c */
int _strcmp(char *s1, char *s2);

/* execute.c */
int run(void);

/* token.c */
char **tokenize_command(char *str, const char *delim);

/* token.c */
int exec(const char *command, char *const arguments[], char *const env[]);

/*execute.c */
int execute(char *arguments[]);

/* token.c */
void print_env(char **arv __attribute__ ((unused)));

/* execute.c */
void isExist(int command_length, char *command);

/* _getline.c */
char *_getenv(const char *name);

/* token.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* _getline.c */
void contol_C(int sig_num);

/* _getline.c */
list_path *pathstrok(char *path);

/* function.c */
char *any_Path(char *filename, list_path *head);

/* function.c */
char *search_Path(char *name, char *sep, char *value);

/* function.c */
list_path *end_node(list_path **head, char *str);

/* function.c */
void free_Arguments(char **arv);

/* function */
void free_linked(list_path *head);

/* _getline.c */
void pro_Exit(char **arguments);

/* _getline.c */
int _converter(char *str);

/* execute.c */
void(*isBuild(char **arv))(char **arv);

#endif
