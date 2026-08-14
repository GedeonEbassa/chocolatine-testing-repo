/*
** EPITECH PROJECT, 2026
** File contains setenv
** File description:
** File contains setenv
*/

#include "../include/my.h"

char *create_variable(char *name, char *value)
{
    char *new;

    new = malloc(my_strlen(name) + my_strlen(value) + 2);
    my_strcpy(new, name);
    my_strcat(new, "=");
    my_strcat(new, value);
    return new;
}

int find_variable(char **env, char *name)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 0 &&
            env[i][my_strlen(name)] == '=')
            return i;
        i++;
    }
    return -1;
}

void append_variable(char ***env, char *new)
{
    char **copy;
    int len = count_arr(*env);
    int i = 0;

    copy = malloc(sizeof(char *) * (len + 2));
    while (i < len) {
        copy[i] = (*env)[i];
        i++;
    }
    copy[len] = new;
    copy[len + 1] = NULL;
    free(*env);
    *env = copy;
}

int builtin_setenv(char ***env, char *name, char *value)
{
    int index;
    char *new;

    if (name == NULL)
        return builtin_env(*env);
    if (value == NULL)
        value = "";
    new = create_variable(name, value);
    index = find_variable(*env, name);
    if (index != -1) {
        free((*env)[index]);
        (*env)[index] = new;
    } else
        append_variable(env, new);
    return 0;
}
