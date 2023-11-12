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
 * _printInt - writes the integer c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printInt(size_t c)
{
    char buffer[20]; /* Assuming a maximum of 20 digits */
    int i = 0;
    int j;

	if (c == 0) {
        _printchar('0'); /* If the size_t value is 0, print '0' */
        return 0;
    }

    /* Extract and store the digits in reverse order */
    while (c > 0) {
        buffer[i] = '0' + (c % 10); /* Convert the digit to a character */
        c /= 10;
        i++;
    }

    /* Print the digits in reverse order */
    for (j = i - 1; j >= 0; j--) {
        _printchar(buffer[j]);
    }

    return 0;
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

    len = _strlen(str) + 1;  /* +1 for the null terminator */

    copy = (char*)malloc(len);
    if (copy != NULL) {
        _strcpy(copy, str);
    }

    return copy;
}

int _strncmp(const char *str1, const char *str2, size_t n) {
    while (n > 0 && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
        n--;
    }

    if (n == 0) {
        return 0;
    } else {
        return *(unsigned char *)str1 - *(unsigned char *)str2;
    }
}

char *_strstr(const char *haystack, const char *needle) {
    while (*haystack) {
        const char *hay_ptr = haystack;
        const char *needle_ptr = needle;

        while (*hay_ptr && *needle_ptr && (*hay_ptr == *needle_ptr)) {
            hay_ptr++;
            needle_ptr++;
        }

        if (!(*needle_ptr)) {
            return (char *)haystack;
        }

        haystack++;
    }

    return NULL;
}

char *_strncpy(char *dest, const char *src, size_t n) {
    char *dest_ptr = dest;
    const char *src_ptr = src;

    size_t i;
    for (i = 0; i < n && src_ptr[i] != '\0'; i++) {
        dest_ptr[i] = src_ptr[i];
    }

    for (; i < n; i++) {
        dest_ptr[i] = '\0';
    }

    return dest;
}
