/*
** EPITECH PROJECT, 2022
** my_cd.c
** File description:
** my_cd
*/

#include "mysh.h"

int cd_command(char **tab, env_t *env)
{
    int size_tab = 0;
    char *pwd = NULL;
    size_t size = MAX_PWD;
    for (size_tab = 0; tab[size_tab] != NULL; size_tab++) { }
    if (size_tab > 2) {
        my_print_err("cd: Too many arguments.\n");
        return 1;
    }
    if (size_tab == 1) {
        return cd_home(env);
    }
    if (size_tab == 2 && my_strcmp(tab[1], "-") == 0) {
        return go_oldpwd(env);
    }
    if (size_tab == 2) {
        return cd_command2(tab, env);
    }
    return 0;
}

int get_home_id(char **env)
{
    char *cpy;
    for (int i = 0; env[i] != NULL; i++) {
        cpy = my_strdup(env[i]);
        cpy[4] = '\0';
        if (my_strcmp(cpy, "HOME") == 0) {
            free(cpy);
            return i;
        }
        free(cpy);
    }
    return -1;
}

int cd_home(env_t *env)
{
    int ret_val = 0;
    char *home = NULL;
    int ret = 0;
    size_t size = MAX_PWD;
    char *oldpwd = NULL;

    oldpwd = getcwd(oldpwd, size);
    home = my_strdup(&env->env[get_home_id(env->env)][5]);
    ret = chdir(home);
    if (ret == -1) {
        my_print_err(home);
        my_print_err(": No such file or directory.\n");
        ret_val = 1;
    } else {
        my_setenv(env, "OLDPWD", oldpwd);
        modif_pwd_env(env);
    }
    free(home);
    free(oldpwd);
    return ret_val;
}

int error_cd(char **tab)
{
    int ret_val = 0;

    if (is_a_dir(tab[1]) == 0) {
        my_print_err(tab[1]);
        my_print_err(": Not a directory.\n");
        ret_val = 1;
    } else {
        my_print_err(tab[1]);
        my_print_err(": No such file or directory.\n");
        ret_val = 1;
    }
    return ret_val;
}

int cd_command2(char **tab, env_t *env)
{
    int ret_val = 0;
    char *pwd = NULL;
    int ret1 = 0;
    size_t size = MAX_PWD;
    char *oldpwd = NULL;

    oldpwd = getcwd(oldpwd, size);
    ret1 = chdir(tab[1]);
    if (ret1 == -1) {
        ret_val = error_cd(tab);
    } else {
        my_setenv(env, "OLDPWD", oldpwd);
        modif_pwd_env(env);
    }
    free(oldpwd);
    return ret_val;
}
