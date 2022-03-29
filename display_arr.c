/*
** EPITECH PROJECT, 2022
** display_env.c
** File description:
** display_env
*/

#include "my.h"
#include <stdlib.h>

void display_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        my_printf("%s\n", arr[i]);
    }
}
