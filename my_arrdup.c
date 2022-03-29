/*
** EPITECH PROJECT, 2022
** my_arrdup.c
** File description:
** my_arrdup
*/

#include "my.h"
#include <stdlib.h>

char **my_arrdup(char **arr)
{
    char **new;
    int size = 0;
    int i = 0;

    for (size = 0; arr[size] != NULL; size++);
    new = malloc((size + 2) * sizeof(char *) + sizeof(NULL));
    for (i = 0; arr[i] != NULL; i++)
        new[i] = my_strdup(arr[i]);
    new[i] = NULL;
    return new;
}

char **increase_size_arr(char **arr)
{
    char **tmp;
    int size = 0;
    int i = 0;

    for (size = 0; arr[size] != NULL; size++);
    tmp = malloc((size + 2) * sizeof(char *));
    for (i = 0; arr[i] != NULL; i++) {
        tmp[i] = my_strdup(arr[i]);
        free(arr[i]);
    }
    tmp[i] = NULL;
    free(arr);
    return tmp;
}
