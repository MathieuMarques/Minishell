/*
** EPITECH PROJECT, 2022
** mysh2.c
** File description:
** mysh2
*/

#include "mysh.h"

void display_prompt(void)
{
    int i = 0;
    char *pwd = NULL;
    size_t size = MAX_PWD;
    pwd = getcwd(pwd, size);
    my_revstr(pwd);
    for (i = 0; pwd[i] != '\0' && pwd[i] != '/'; i++);
    pwd[i] = '\0';
    my_revstr(pwd);
    my_printf("[%s]$ ", pwd);
    free(pwd);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}

int get_path(char **env)
{
    char *cpy;

    for (int i = 0; env[i] != NULL; i++) {
        cpy = my_strdup(env[i]);
        cpy[4] = '\0';
        if (my_strcmp(cpy, "PATH") == 0) {
            free(cpy);
            return i;
        }
        free(cpy);
    }
    return -1;
}

char **get_tab_path(env_t *env)
{
    int path = get_path(env->env);
    char **tab_path;
    if (path == -1) {
        tab_path = malloc(sizeof(char *));
        tab_path[0] = NULL;
    } else {
    tab_path = path_to_tab(&env->env[path][5]);
    }
    return tab_path;
}

int error_handler_mysh(int status)
{
    if (!WIFEXITED(status)) {
        if (WTERMSIG(status) == SIGSEGV && WCOREDUMP(status))
            my_print_err("Segmentation fault (core dumped)\n");
        if (WTERMSIG(status) == SIGSEGV && !WCOREDUMP(status))
            my_print_err("Segmentation fault\n");
    } else {
        if (status == 256)
            status = 1;
    }
    return status;
}
