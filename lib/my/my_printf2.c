/*
** EPITECH PROJECT, 2021
** my_printf2.c
** File description:
** my_printf2
*/

#include <stdarg.h>
#include "../../include/my.h"
#include <stdlib.h>

int my_printf_display_arg2(char *format, int n, va_list arg)
{
    switch (format[0]) {
    case 'b':
        print_binary(va_arg(arg, unsigned int));
        return 0 + n;
    case '%':
        my_putchar('%');
        return 0 + n;
    case 'l':
        if (format[1] == 'l') {
            my_put_nbrll(va_arg(arg, long long));
            return 1 + n;
        } else
            my_put_nbrl(va_arg(arg, long));
        return 0 + n;
    default:
        return my_printf_display_arg3(format, n, arg);
    }
}

int my_printf_display_arg3(char *format, int n, va_list arg)
{
    switch (format[0]) {
    case 'x':
    case 'X':
        if (format[0] == 'x')
            print_in_hexa(va_arg(arg, unsigned int), "abcdef");
        else
            print_in_hexa(va_arg(arg, unsigned int), "ABCDEF");
        return 0 + n;
    case 'o':
        print_in_octal(va_arg(arg, unsigned int));
        return 0 + n;
    case 'u':
        my_put_nbru(va_arg(arg, unsigned int));
        return 0 + n;
    default:
        return my_printf_display_arg4(format, n, arg);
    }
}

int my_printf_display_arg4(char *format, int n, va_list arg)
{
    switch (format[0]) {
    case '#':
        n = cond_arg(format, n, arg);
        return n;
    case 'p':
        my_putstr("0x");
        print_in_hexa((long)va_arg(arg, void *), "abcdef");
        return 0 + n;
    case 'C':
        print_maj_c(va_arg(arg, int));
        return n;
    default:
        my_putchar('%');
        my_putchar(format[0]);
        return 0 + n;
    }
}

void print_binary(unsigned int nb)
{
    char *nbr = malloc(nb * sizeof(char));
    int i = 0;
    for (i = 0; nb >= 1; i++) {
        nbr[i] = (nb % 2) + '0';
        nb /= 2;
    }
    nbr[i + 1] = '\0';
    my_revstr(nbr);
    my_putstr(nbr);
    free(nbr);
}
