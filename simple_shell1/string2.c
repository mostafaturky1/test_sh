#include "shell.h"

/**
 * _printchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printchar(char c)
{
	return (write(1, &c, 1));
}

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

char* _strdup(const char* str) {
    size_t len;
    char* copy;

    if (str == NULL) {
        return NULL;  /*  Handle the case of a NULL input string. */
    }

    len = strlen(str) + 1;  /* +1 for the null terminator */

    copy = (char*)malloc(len);
    if (copy != NULL) {
        _strcpy(copy, str);
    }

    return copy;
}
