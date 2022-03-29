/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** allocates memories and copies the string given as argument in it
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(str, src);
    return (str);
}
