/*
** EPITECH PROJECT, 2026
** File contains execve functions
** File description:
** file containing execve functions
*/

#include "../include/my.h"

void print_signal_error(int status)
{
    int sig = WTERMSIG(status);

    if (sig == SIGSEGV) {
        write(2, "Segmentation fault", 18);
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
    }
}

int command_error(char *cmd, char **cmdline)
{
    if (cmd != NULL)
        return 0;
    write(2, cmdline[0], my_strlen(cmdline[0]));
    write(2, ": Command not found.\n", 21);
    return 1;
}

int child_process(char *cmd, char **cmdline, char **env)
{
    execve(cmd, cmdline, env);
    perror(cmd);
    exit(84);
}

int parent_process(pid_t pid, int *status, char **cmdline)
{
    waitpid(pid, status, 0);
    if (WIFSIGNALED(*status)) {
        print_signal_error(*status);
        return 84;
    }
    if (WIFEXITED(*status))
        return WEXITSTATUS(*status);
    return *status;
}

int callexecve(char **cmdline, char **env)
{
    char *cmd = cmd_verif(cmdline[0], env);
    pid_t pid;
    int status = 0;

    if (command_error(cmd, cmdline))
        return 84;
    pid = fork();
    if (pid == 0)
        child_process(cmd, cmdline, env);
    if (pid > 0)
        return parent_process(pid, &status, cmdline);
    perror("fork");
    return 0;
}
