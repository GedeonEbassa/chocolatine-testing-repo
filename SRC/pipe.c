/*
** EPITECH PROJECT, 2026
** Minishell
** File description:
** Pipe handling functions
*/

#include "../include/my.h"

int exec_pipe_left(char *cmd, int *pipefds, char ***env)
{
    pid_t pid = fork();

    if (pid == -1)
        return 84;
    if (pid == 0) {
        close(pipefds[0]);
        dup2(pipefds[1], STDOUT_FILENO);
        close(pipefds[1]);
        exit(execute_command(trim(cmd), env));
    }
    return pid;
}

int setup_pipe_input(int *pipefds)
{
    int copy_in = dup(STDIN_FILENO);

    dup2(pipefds[0], STDIN_FILENO);
    close(pipefds[0]);
    return copy_in;
}

int handle_pipes(char *buff, char ***env)
{
    int pipefds[2];
    int copy_in;
    int left_pid;
    int status = 0;
    char **cmds = my_str_to_word_array(buff, "|");

    if (count_arr(cmds) < 2) {
        free_array(cmds);
        return -1;
    }
    if (pipe(pipefds) == -1)
        return 84;
    exec_pipe_left(cmds[0], pipefds, env);
    close(pipefds[1]);
    copy_in = setup_pipe_input(pipefds);
    status = execute_command(trim(buff + my_strlen(cmds[0]) + 1), env);
    dup2(copy_in, STDIN_FILENO);
    close(copy_in);
    free_array(cmds);
    return status;
}
