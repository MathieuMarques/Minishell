/*
** EPITECH PROJECT, 2022
** mysh.c
** File description:
** mysh
*/

#include "mysh.h"

int mysh(char **env)
{
    char *line = NULL;
    size_t size = 0;
    int ret = 0;
    int ret_val = 0;
    env_t *envi = create_env_t(env);

    display_prompt();
    signal(SIGINT, handler);
    signal(SIGTSTP, handler);
    while (ret = getline(&line, &size, stdin) != -1) {
        if (ret > 0) {
            ret_val = exec_command(line, envi);
            display_prompt();
            ret = 0;
        }
    }
    free(line);
    free_env(envi);
    my_printf("exit\n");
    return ret_val;
}

int exec_command(char *line, env_t *env)
{
    int ret = 0;
    pid_t pid;
    char **tab;
    int path = 0;
    char **tab_path;
    if (my_strcmp(line, "\n") == 0)
        return 0;
    tab = str_to_tab(line);
    if (tab[0] == NULL)
        return 0;
    if (ret = do_special_cmd(tab, env) != -1)
        return ret;
    tab_path = get_tab_path(env);
    pid = fork();
    if (pid != 0)
        return do_father(tab, tab_path);
    else
        do_child(tab, env->env, tab_path);
    return 0;
}

int do_child(char **tab, char **env, char **tab_path)
{
    char *cpy;

    if (access(tab[0], X_OK) == 0)
        execve(tab[0], tab, env);
    for (int i = 0; tab_path[i] != NULL; i++) {
        cpy = my_strdup(tab_path[i]);
        my_strcat(cpy, "/");
        my_strcat(cpy, tab[0]);
        if (access(cpy, X_OK) == 0)
            execve(cpy, tab, env);
        free(cpy);
    }
    my_print_err(tab[0]);
    my_print_err(": Command not found.\n");
    exit(1);
}

int do_father(char **tab, char **tab_path)
{
    int status = 0;

    wait(&status);
    status = error_handler_mysh(status);
    free_tab(tab);
    free_tab(tab_path);
    return status;
}
