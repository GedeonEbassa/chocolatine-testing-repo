/*
** EPITECH PROJECT, 2026
** File contains builtin functions
** File description:
** file containing builtin functions
*/

#include "../include/my.h"

int builtin_env(char **env)
{
    int i = 0;

    for (i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
    return 0;
}

char *find_home(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "HOME=", 5) == 0)
            return env[i] + 5;
        i++;
    }
    return NULL;
}

char *find_pwd(char **env, int type)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PWD=", 4) == 0 && type == 0)
            return env[i] + 4;
        if (my_strncmp(env[i], "OLDPWD=", 7) == 0 && type == 1)
            return env[i] + 7;
        i++;
    }
    return NULL;
}

void update_pwd(char ***env, char *old)
{
    char cwd[4096];

    getcwd(cwd, 4096);
    builtin_setenv(env, "OLDPWD", old);
    builtin_setenv(env, "PWD", cwd);
}

int builtin_cd(char ***env, char *path)
{
    char *home;
    char *old;

    if (path != NULL && my_strcmp(path, "-") == 0) {
        builtin_cd(env, find_pwd(*env, 1));
        return 0;
    }
    old = find_pwd(*env, 0);
    home = path;
    if (home == NULL)
        home = find_home(*env);
    if (home == NULL)
        return 84;
    if (chdir(home) == -1) {
        my_printf("%s: No such file or directory.\n", home);
        return 84;
    }
    update_pwd(env, old);
    return 0;
}
