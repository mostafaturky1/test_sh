#include "string.h"

#include <stddef.h>

size_t _strlen(const char *str)
{
    const char *temp = str;

    if (str == NULL) {
        return 0;
    }
    while (*temp) {
        temp++;
    }
    return (size_t)(temp - str);
}

char *_strcpy(char *dest, const char *src)
{   size_t src_len = 0;
    size_t i;
    if (src == NULL) {
        return NULL;
    } 
    while (src[src_len] != '\0') {
        src_len++;
    }
        dest = (char *)malloc(src_len + 1);
    if (dest == NULL)
    {
        return NULL;
    }
    for (i = 0; i <= src_len; i++) {
        dest[i] = src[i];
    }
    return dest;
}

int _strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    
    if (*str1 == *str2) {
        return 0;
    } else if (*str1 < *str2) {
        return -1;
    } else {
        return 1;
    }
}

char *_strcat(char *dest, const char *src)
{
    size_t i;
    size_t dest_len = _strlen(dest);
    size_t src_len = _strlen(src);
    char *new_str = NULL;
    
    if (new_str == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    _strcpy(new_str, dest);
    
    for (i = 0; i <= src_len; i++) {
        new_str[dest_len + i] = src[i];
    }

    return new_str;
}

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


