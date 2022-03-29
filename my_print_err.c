/*
** EPITECH PROJECT, 2022
** my_print_err.c
** File description:
** my_print_err
*/

#include "mysh.h"

void my_print_err(char *str)
{
    int len = my_strlen(str);
    write(2, str, len);
}
