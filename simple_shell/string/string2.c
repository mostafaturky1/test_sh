#include "string.h"

/**
 * _print - prints a string
 * @str: pointer to string
 */

void _print(char *str)
{
	int i = 0;

	while (str[i])
	{
		_printchar(str[i]);
		i++;
	}
}

char *_strtok(char *str, const char *delim) {
    static char *nextToken = NULL;
    char *tokenStart;

    if (str != NULL) {
        nextToken = str;
    }
    if (nextToken == NULL || delim == NULL || *nextToken == '\0') {
        return NULL;
    }
    while (*nextToken != '\0' && _strchr(delim, *nextToken) != NULL) {
        nextToken++;
    }
    if (*nextToken == '\0') {
        return NULL;
    }
    tokenStart = nextToken;
    while (*nextToken != '\0' && _strchr(delim, *nextToken) == NULL) {
        nextToken++;
    }
    if (*nextToken != '\0') {
        *nextToken = '\0';
        nextToken++;
    }
    return tokenStart;
}

char *_strchr(const char *str, int ch) {
    while (*str != '\0') {
        if (*str == (char)ch) {
            return (char *)str;
        }
        str++;
    }

    if (ch == '\0') {
        return (char *)str;
    }

    return NULL;  
}