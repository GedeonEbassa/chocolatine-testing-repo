/*
** EPITECH PROJECT, 2026
** Minishell
** File description:
** File trim.c
*/

#include "../include/my.h"

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\r');
}

char *trim(char *s)
{
    char *end;

    while (is_space(*s))
        s++;
    if (!*s)
        return s;
    end = s + my_strlen(s) - 1;
    while (end > s && is_space(*end)) {
        *end = '\0';
        end--;
    }
    return s;
}

char *find_space(char *s)
{
    while (*s && !is_space(*s))
        s++;
    if (*s)
        return s;
    else
        return NULL;
}

char *find_char(char *s, char c)
{
    while (*s && *s != c)
        s++;
    if (*s)
        return s;
    else
        return NULL;
}

char *strip_n(char *s)
{
    char *h = find_char(s, '\n');

    if (!h || h == s)
        return s;
    *h = '\0';
    return trim(s);
}
