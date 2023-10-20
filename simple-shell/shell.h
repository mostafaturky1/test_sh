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

/* string2.c */
int _printchar(char c);

/* string2.c */
void _print(char *str);

/* string.c */
char *_strdup(char *str);

/* string.c */
void _strcpy(char *dest, char *src);

/* string.c */
int _strlen(char *s);

/* string.c */
int _strcmp(char *s1, char *s2);

/* string.c */
char *_strcat(char *destination, const char *source);

/* execute.c */
int run(void);

/* token.c */
char **tokenize(char *str, const char *delim);

/* token.c */
int exec(const char *command, char *const arguments[], char *const env[]);

/*execute.c */
int execute(char *arguments[]);

/* token.c */
void print_env(char **arv __attribute__ ((unused)));

/* execute.c */
int isExist(int command_length, char *command);

/* _getline.c */
char *_getenv(const char *name);

/* _getline.c */
void contol_C(int sig_num);

/* string2.c */
void free_Arguments(char **arv);

/* _getline.c */
void pro_Exit(char **arguments);

/* _getline.c */
int _converter(char *str);


#endif
