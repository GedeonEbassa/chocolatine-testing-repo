/*
** EPITECH PROJECT, 2026
** File contains setenv
** File description:
** File contains setenv
*/

#include "../include/my.h"

void copy_without(char **copy, char **env, int skip)
{
    int i = 0;
    int j = 0;

    while (env[i] != NULL) {
        if (i != skip) {
            copy[j] = env[i];
            j++;
        }
        i++;
    }
    copy[j] = NULL;
}

int builtin_unsetenv(char ***env, char *name)
{
    char **copy;
    int index;
    int len;

    if (name == NULL)
        return 84;
    index = find_variable(*env, name);
    if (index == -1)
        return 0;
    len = count_arr(*env);
    copy = malloc(sizeof(char *) * len);
    free((*env)[index]);
    copy_without(copy, *env, index);
    free(*env);
    *env = copy;
    return 0;
}
