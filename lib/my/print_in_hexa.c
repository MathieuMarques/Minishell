/*
** EPITECH PROJECT, 2021
** print_in_hexa.c
** File description:
** print_in_hexa
*/

#include "../../include/my.h"
#include <stdlib.h>

void print_in_hexa(unsigned int nb, char *base)
{
    int result = 0;
    char *print_result = malloc((find_power_malloc(nb) + 1) * sizeof(char));
    for (int i = 0; nb != 0; i++) {
        result = nb % 16;
        if (result > 9)
            print_result[i] = base[result - 10];
        else
            print_result[i] = result + '0';
        nb /= 16;
    }
    my_revstr(print_result);
    my_putstr(print_result);
    free(print_result);
}

int find_power_malloc(int unsigned nb)
{
    int i;
    i = 1;
    while (i - 1 < nb / 10) {
        i++;
    }
    return (i);
}
