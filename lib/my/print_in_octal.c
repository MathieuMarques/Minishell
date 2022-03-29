/*
** EPITECH PROJECT, 2021
** print_in_oct.c
** File description:
** print the oct value of the char
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/my_macro_abs.h"

void print_in_octal3(char c)
{
    char *nbr = malloc(4 * sizeof(char));
    int oct = get_octal_value(c);
    nbr = int_to_str(oct);
    my_revstr(nbr);
    for (int i = my_strlen(nbr); i < 3; i++) {
        nbr[i] = '0';
    }
    nbr[4] = '\0';
    my_revstr(nbr);
    my_putstr(nbr);
    free(nbr);
}

char *int_to_str(int nb)
{
    char *nbr = malloc(12 * sizeof(char));
    int i = 0;
    int is_neg = 0;
    if (nb < 0)
        is_neg = 1;
    nb = ABS(nb);
    for (i; nb != 0; i++) {
        nbr[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    if (is_neg == 1) {
        nbr[i] = '-';
        nbr[i + 1] = '\0';
    } else
        nbr[i] = '\0';
    nbr = my_revstr(nbr);
    return nbr;
}

int get_octal_value(char c)
{
    int result = 0;
    for (int i = 0; i < c; i++) {
        result++;
        if ((result % 10) >= 8) {
            result -= 8;
            result += 10;
        }
    }
    return result;
}

void print_in_octal(unsigned int nb)
{
    char *result = malloc((find_power_malloc(nb) * 2 + 1) * sizeof(char));
    for (int i = 0; nb != 0; i++) {
        result[i] = (nb % 8) + '0';
        nb /= 8;
    }
    my_revstr(result);
    my_putstr(result);
    free(result);
}
