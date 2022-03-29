/*
** EPITECH PROJECT, 2021
** print_maj_c.c
** File description:
** print_maj_c
*/

#include "../../include/my.h"

void print_maj_c(char c)
{
    if (my_char_isprintable(c) == 0) {
        my_putchar('\\');
        print_in_octal3(c);
    } else {
        my_putchar(c);
    }
}
