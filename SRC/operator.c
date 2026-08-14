/*
** EPITECH PROJECT, 2026
** Main file
** File description:
** handling operators
*/

#include "../include/my.h"

int redirect_out(char *buff, char *filename, char ***env)
{
    int file;
    int copy_out;
    int status = 0;
    char *clean_file = trim(filename);

    file = open(clean_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file == -1) {
        perror(clean_file);
        return 1;
    }
    copy_out = dup(STDOUT_FILENO);
    dup2(file, STDOUT_FILENO);
    status = execute_command(buff, env);
    dup2(copy_out, STDOUT_FILENO);
    close(copy_out);
    return status;
}

int redirect_in(char *cmd, char *filename, char ***env)
{
    int file;
    int copy_in;
    int status;
    char *clean_file = trim(filename);

    file = open(clean_file, O_RDONLY);
    if (file == -1) {
        my_printf("%s: No such file or directory.\n", clean_file);
        return 1;
    }
    copy_in = dup(STDIN_FILENO);
    dup2(file, STDIN_FILENO);
    close(file);
    status = execute_command(trim(cmd), env);
    dup2(copy_in, STDIN_FILENO);
    close(copy_in);
    return status;
}

int comparison_operators(char *buff, char ***env)
{
    char **cmds;
    int status = handle_double_operators(buff, env);

    if (status != -1)
        return status;
    if (count_char(buff, '>') == 1) {
        cmds = my_str_to_word_array(buff, ">");
        return redirect_out(cmds[0], cmds[1], env);
    }
    if (count_char(buff, '<') == 1) {
        cmds = my_str_to_word_array(buff, "<");
        return redirect_in(cmds[0], cmds[1], env);
    }
    return -1;
}

int handle_operators(char *buff, char ***env)
{
    char **cmds;
    int status = -1;

    if (find_char(buff, ';')) {
        cmds = my_str_to_word_array(buff, ";");
        while (*cmds != NULL) {
            status = execute_command(*cmds, env);
            cmds++;
        }
        return status;
    }
    if (find_char(buff, '|'))
        return handle_pipes(buff, env);
    status = comparison_operators(buff, env);
    return status;
}
