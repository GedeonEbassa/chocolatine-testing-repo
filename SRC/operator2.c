/*
** EPITECH PROJECT, 2026
** Main file
** File description:
** handling other operators
*/

#include "../include/my.h"

void write_heredoc_lines(int write_fd, char *delimiter)
{
    char *line = NULL;
    size_t len = 0;
    char *clean_delim = trim(delimiter);

    while (1) {
        my_printf("? ");
        if (getline(&line, &len, stdin) == -1)
            break;
        if (my_strncmp(line, clean_delim, my_strlen(clean_delim)) == 0 &&
            line[my_strlen(clean_delim)] == '\n') {
            free(line);
            break;
        }
        write(write_fd, line, my_strlen(line));
    }
}

int redirect_heredoc(char *cmd, char *delimiter, char ***env)
{
    int pipefds[2];
    int copy_in;
    int status;

    if (pipe(pipefds) == -1)
        return 84;
    write_heredoc_lines(pipefds[1], delimiter);
    close(pipefds[1]);
    copy_in = dup(STDIN_FILENO);
    dup2(pipefds[0], STDIN_FILENO);
    close(pipefds[0]);
    status = execute_command(trim(cmd), env);
    dup2(copy_in, STDIN_FILENO);
    close(copy_in);
    return status;
}

int redirect_append(char *cmd, char *filename, char ***env)
{
    int file;
    int copy_out;
    int status;
    char *clean_file = trim(filename);

    file = open(clean_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file == -1) {
        perror(clean_file);
        return 1;
    }
    copy_out = dup(STDOUT_FILENO);
    dup2(file, STDOUT_FILENO);
    close(file);
    status = execute_command(trim(cmd), env);
    dup2(copy_out, STDOUT_FILENO);
    close(copy_out);
    return status;
}

int handle_double_operators(char *buff, char ***env)
{
    char **cmds;

    if (my_strstr(buff, ">>") != NULL) {
        cmds = my_str_to_word_array(buff, ">>");
        return redirect_append(cmds[0], cmds[1], env);
    }
    if (my_strstr(buff, "<<") != NULL) {
        cmds = my_str_to_word_array(buff, "<<");
        return redirect_heredoc(cmds[0], cmds[1], env);
    }
    return -1;
}
