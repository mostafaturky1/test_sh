#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
*/
int _strlen(char *s)
{
        int longi = 0;

        while (*s != '\0')
        {
                longi++;
                s++;
        }

        return (longi);
}

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
*/
char *_strcpy(char *dest, char *src)
{
        int l = 0;
        int x = 0;

        while (*(src + l) != '\0')
        {
                l++;
        }
        for ( ; x < l ; x++)
        {
                dest[x] = src[x];
        }
        dest[l] = '\0';
        return (dest);
}

/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: 0
*/
char *_strdup(const char *str)
{
        char *aaa = NULL;
        int i, r = 0;

        if (str == NULL)
                return (NULL);
        i = 0;
        while (str[i] != '\0')
                i++;

        aaa = malloc(sizeof(char) * (i + 1));

        if (aaa == NULL)
                return (NULL);

        for (r = 0; str[r]; r++){
                aaa[r] = str[r];
        }
        return (aaa);
}

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
*/
int _strcmp(char *s1, char *s2)
{
        int i;

        i = 0;
        while (s1[i] != '\0' && s2[i] != '\0')
        {
                if (s1[i] != s2[i])
                {
                        return (s1[i] - s2[i]);
                }
                i++;
        }
        return (0);
}

