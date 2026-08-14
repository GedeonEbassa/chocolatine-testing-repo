/*
** EPITECH PROJECT, 2026
** my_radar
** File description:
** function responsible for handling strings
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int last_char = my_strlen(dest);

    for (i = 0; i < my_strlen(src); i++) {
        dest[last_char] = src[i];
        last_char++;
    }
    dest[last_char] = '\0';
    return dest;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; i < my_strlen(src); i++)
        dest[i] = src[i];
    dest[i] = '\0';
    i++;
    return dest;
}

int my_strncmp(char *str1, char *str2, int l)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && i < l) {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return 0;
}

void remove_tabs(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] != '\t') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

int count_char(char *s, char c)
{
    int num = 0;

    while (*s) {
        if (*s == c)
            num++;
        s++;
    }
    return num;
}
