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
    /* Find the null terminator of dest */
    size_t dest_len = 0, i;

    while (dest[dest_len] != '\0') {
        dest_len++;
    }

    /*  Copy the characters from src to dest, starting from the null terminator of dest */
    i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }

    /*  Null-terminate the resulting string */
    dest[dest_len + i] = '\0';

    return dest;
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

char* _strrchr(const char* str, int character) {
    const char* last = NULL;

    while (*str) {
        if (*str == character) {
            last = str;
        }
        str++;
    }

    return (char*)last;
}
