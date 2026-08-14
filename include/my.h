/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** minishell
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/syscall.h>
    #include <signal.h>

int callexecve(char **cmdline, char **env);
char **my_str_to_word_array(char const *str, char *delimiter);
int my_strlen(char const *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *str1, char const *str2);
int my_strncmp(char *s1, char *s2, int l);
int my_printf(const char *format, ...);
void free_array(char **arr);
char *my_strcat(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);
char *cmd_verif(char *command, char **env);
char **copy_env(char **env);
int count_arr(char **arr);
char *my_strcpy(char *dest, char const *src);
int builtin_env(char **env);
int builtin_setenv(char ***env, char *name, char *value);
int builtin_cd(char ***env, char *path);
int builtin_unsetenv(char ***env, char *name);
void append_variable(char ***env, char *new);
int find_variable(char **env, char *name);
char *create_variable(char *name, char *value);
char *trim(char *s);
char *strip_n(char *s);
void remove_tabs(char *str);
char *find_char(char *s, char c);
int handle_operators(char *buff, char ***env);
int execute_command(char *buff, char ***env);
int count_char(char *s, char c);
int handle_double_operators(char *buff, char ***env);
int handle_pipes(char *buff, char ***env);
int redirect_heredoc(char *cmd, char *delimiter, char ***env);
#endif //MY_H
