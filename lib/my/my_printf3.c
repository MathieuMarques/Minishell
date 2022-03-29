/*
** EPITECH PROJECT, 2021
** my_printf3.c
** File description:
** my_printf3
*/

#include <stdarg.h>
#include "../../include/my.h"
#include <stdlib.h>

int cond_arg(char *format, int n, va_list arg)
{
    if (format[1] == 'x') {
        my_putstr("0x");
        n = my_printf_display_arg(&format[1], 1, arg);
        return n;
    }
    if (format[1] == 'X') {
        my_putstr("0X");
        n = my_printf_display_arg(&format[1], 1, arg);
        return n;
    }
    if (format[1] == 'o') {
        my_putchar('0');
        n = my_printf_display_arg(&format[1], 1, arg);
        return n;
    }
    n = my_printf_display_arg(&format[1], 1, arg);
    return n;
}
