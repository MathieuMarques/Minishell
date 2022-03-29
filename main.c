/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "mysh.h"

void handler(int signum)
{
    my_printf("\n");
    display_prompt();
}

int get_pwd_id(char **env)
{
    char *cpy;
    for (int i = 0; env[i] != NULL; i++) {
        cpy = my_strdup(env[i]);
        cpy[3] = '\0';
        if (my_strcmp(cpy, "PWD") == 0) {
            free(cpy);
            return i;
        }
        free(cpy);
    }
    return -1;
}

char *get_pwd(char **env)
{
    char *cpy;
    char *pwd;
    int i = get_pwd_id(env);
    if (i == -1)
        return NULL;
    int j = 0;
    cpy = my_strdup(env[i]);
    my_revstr(cpy);
    for (j = 0; cpy[j] != '\0' && cpy[j] != '/'; j++);
    cpy[j] = '\0';
    pwd = my_strdup(cpy);
    free(cpy);
    my_revstr(pwd);
    return pwd;
}

int main(int argc, char **argv, char **env)
{
    if (argc != 1)
        return 84;
    return mysh(env);
}
