/*
** EPITECH PROJECT, 2026
** File contains file functions
** File description:
** file containing file functions
*/

#include "../include/my.h"

char *cmd_verif2(char *command, char *line)
{
    char *copy = my_strdup(line + 5);
    char *token = strtok(copy, ":");
    char *filepath = NULL;

    while (token != NULL) {
        filepath = malloc(sizeof(char) *
            (my_strlen(token) + my_strlen(command) + 2));
        my_strcpy(filepath, token);
        my_strcat(filepath, "/");
        my_strcat(filepath, command);
        if (access(filepath, X_OK) == 0)
            return filepath;
        free(filepath);
        token = strtok(NULL, ":");
    }
    free(copy);
    return NULL;
}

char *cmd_verif(char *command, char **env)
{
    int i = 0;

    if (access(command, X_OK) == 0)
        return command;
    if (env == NULL)
        return NULL;
    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            break;
    }
    if (env[i] == NULL)
        return NULL;
    return cmd_verif2(command, env[i]);
}

char **copy_env(char **env)
{
    int len = count_arr(env);
    char **save_env = malloc(sizeof(char *) * (len + 1));
    int i = 0;

    if (len == 0 || !env || env == NULL)
        return NULL;
    for (i = 0; i < len; i++)
        save_env[i] = my_strdup(env[i]);
    save_env[len] = NULL;
    return save_env;
}
