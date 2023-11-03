#include "shell.h"

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
{
    size_t i;
    if (dest == NULL || src == NULL) {
        return NULL;
    }

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

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

char *_strcat(char *dest, const char *src) {
    size_t dest_len;
    size_t src_len;
    char *new_str = NULL;
    size_t i;
    
    dest_len = _strlen(dest);
    src_len = _strlen(src);
    new_str = (char *)malloc(dest_len + src_len + 1); 
    if (new_str == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    _strcpy(new_str, dest);
    
    for (i = 0; i < src_len; i++) {
        new_str[dest_len + i] = src[i];
    }

    new_str[dest_len + src_len] = '\0';  /*  Add the null-terminator. */

    return new_str;
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
