/*
** EPITECH PROJECT, 2026
** my_radar
** File description:
** function responsible for handling strings
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != 0) {
        count++;
    }
    return count;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; str[j + i] == to_find[j] && to_find[j] != '\0'; j++);
        if (to_find[j] == '\0')
            return str + i;
    }
    return NULL;
}

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return my_strlen(str1) - my_strlen(str2);
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return 0;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    i++;
    return dest;
}

char *my_strdup(char const *src)
{
    int length = my_strlen(src) + 1;
    char *dest = (char *)malloc(length);

    if (dest == NULL)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}
