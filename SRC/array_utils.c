/*
** EPITECH PROJECT, 2026
** Minishell
** File description:
** Minishell
*/

#include "../include/my.h"

void free_array(char **arr)
{
    int i = 0;

    while (arr[i] != NULL) {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int count_arr(char **arr)
{
    int i = 0;

    while (arr[i] != NULL)
        i++;
    return i;
}
