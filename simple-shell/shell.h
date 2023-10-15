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

int _printchar(char c);
void _print(char *str);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_getline(void);
char **tokenize_command(const char *command, int *num_args);
int exec(const char *command, char *const arguments[], char *const environment[]);
int execute(char *arguments[], char *const environment[]);
void get_env(void);
int isExist(int command_length);
int run(void);
void printExit(void);
int is_space_command(const char *comamnd);

#endif