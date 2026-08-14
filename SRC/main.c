/*
** EPITECH PROJECT, 2026
** Main file
** File description:
** holding main functions
*/

#include "../include/my.h"

int execute_builtin(char **cmdline, char ***env)
{
    if (my_strcmp(cmdline[0], "env") == 0)
        return builtin_env(*env);
    if (my_strcmp(cmdline[0], "cd") == 0)
        return builtin_cd(env, cmdline[1]);
    if (my_strcmp(cmdline[0], "setenv") == 0)
        return builtin_setenv(env, cmdline[1], cmdline[2]);
    if (my_strcmp(cmdline[0], "unsetenv") == 0)
        return builtin_unsetenv(env, cmdline[1]);
    return -1;
}

int execute_command(char *buff, char ***env)
{
    char **cmdline;
    int status;

    status = handle_operators(buff, env);
    if (status != -1)
        return status;
    cmdline = my_str_to_word_array(buff, " ");
    status = execute_builtin(cmdline, env);
    if (status == -1)
        status = callexecve(cmdline, *env);
    free_array(cmdline);
    return status;
}

int parse_command(char *buff, size_t *n)
{
    char **array = NULL;

    if (getline(&buff, n, stdin) == -1)
        return -1;
    if (strlen(buff) == 1)
        return 2;
    if (find_char(buff, '\t'))
        remove_tabs(buff);
    buff = strip_n(buff);
    if (my_strcmp(buff, "exit") == 0)
        return -1;
    return 0;
}

int main(int ac, char **av, char **env)
{
    int loop = 1;
    int u = 0;
    size_t n = 2048;
    int status = 0;
    char *buff = malloc(sizeof(char) * 2048);
    char **save_env = copy_env(env);

    if (save_env == NULL)
        return 84;
    while (loop == 1) {
        my_printf("$> ");
        u = parse_command(buff, &n);
        if (u == -1)
            break;
        if (u == 2)
            continue;
        status = execute_command(buff, &save_env);
    }
    free(buff);
    return status;
}
