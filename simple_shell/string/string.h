#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *destination, const char *source);
int _printchar(char c);
void _print(char *str);
char *_strtok(char *str, const char *delim);
har *_strchr(const char *str, int ch);

#endif
