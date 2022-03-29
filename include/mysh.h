/*
** EPITECH PROJECT, 2022
** mysh.h
** File description:
** mysh
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include "my.h"

#ifndef MYSH_H_
    #define MYSH_H_

static const int MAX_PWD = 4096;

typedef struct env_s {
    char **env;
} env_t;

int exec_command(char *line, env_t *env);
char **str_to_tab(char *str);
void free_tab(char **tab);
char **path_to_tab(char *str);
int do_child(char **tab, char **env, char **tab_path);
int do_father(char **tab, char **tab_path);
void my_print_err(char *str);
char *get_pwd(char **env);
int get_pwd_id(char **env);
void display_prompt(void);
int cd_command(char **tab, env_t *env);
int cd_home(env_t *env);
int get_home_id(char **env);
int cd_command2(char **tab, env_t *env);
void modif_pwd_env(env_t *env);
int get_oldpwd_id(char **env);
int go_oldpwd(env_t *env);
int is_a_dir(char *dir);
int is_in_env(char **env, char *name);
void my_setenv(env_t *env, char *name, char *value);
int handler_setenv(env_t *env, char **tab);
void print_error_setenv(int err);
int is_error_setenv(char *name);
int my_unsetenv(env_t *env, char **tab);
void handler(int signum);
char **my_arrdup(char **arr);
char **my_arrdup_more_space(char **arr);
int mysh(char **env);
void display_arr(char **arr);
char **increase_size_arr(char **arr);
void free_env(env_t *env);
env_t *create_env_t(char **env);
int do_exit(char **tab, env_t *env);
int do_special_cmd(char **tab, env_t *env);
int error_handler_mysh(int status);
char **get_tab_path(env_t *env);

#endif /* !MYSH_H_ */
