/*
** EPITECH PROJECT, 2022
** my_cd2.c
** File description:
** my_cd2
*/

#include "mysh.h"

int get_oldpwd_id(char **env)
{
    char *cpy;
    for (int i = 0; env[i] != NULL; i++) {
        cpy = my_strdup(env[i]);
        if (my_strlen(cpy) > 6)
            cpy[6] = '\0';
        if (my_strcmp(cpy, "OLDPWD") == 0) {
            free(cpy);
            return i;
        }
        free(cpy);
    }
    return -1;
}

int go_oldpwd(env_t *env)
{
    int opwd = get_oldpwd_id(env->env);
    if (opwd == -1) {
        my_print_err(": No such file or directory.\n");
        return 1;
    }
    char *oldpwd = my_strdup(&env->env[opwd][7]);
    chdir(oldpwd);
    my_setenv(env, "OLDPWD", oldpwd);
    modif_pwd_env(env);
    return 0;
}

int is_a_dir(char *dir)
{
    struct stat sb;
    int ret = stat(dir, &sb);
    if (ret == -1)
        return -1;
    if (S_ISDIR(sb.st_mode))
        return 1;
    else
        return 0;
}

void modif_pwd_env(env_t *env)
{
    char *pwd = NULL;
    size_t size = MAX_PWD;

    pwd = getcwd(pwd, size);
    my_setenv(env, "PWD", pwd);
    free(pwd);
}
