/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"
#include <stdarg.h>

int my_printf(char *formats, ...)
{
    int n = nbr_of_arg(formats);
    if (n == 0) {
        my_putstr(formats);
    } else {
        va_list arg;
        va_start(arg, formats);
        my_printf_display(formats, arg);
        va_end(arg);
    }
    return 0;
}

int nbr_of_arg(char *formats)
{
    int count = 0;
    for (int i = 0; formats[i] != '\0'; i++) {
        if (formats[i] == '%')
            count++;
    }
    return count;
}

void my_printf_display(char *formats, va_list arg)
{
    int n = 2;
    int i = 0;
    for (i = 0; formats[i] != '%' && formats[i] != '\0'; i++) {
        my_putchar(formats[i]);
    }
    if (formats[i] == '\0') {
        return;
    } else if (formats[i] == '%') {
        n += my_printf_display_arg(&formats[i + 1], 0, arg);
    }
    my_printf_display(&formats[i + n], arg);
}

int my_printf_display_arg(char *format, int n, va_list arg)
{
    switch (format[0]) {
    case 's':
        my_putstr(va_arg(arg, char *));
        return 0 + n;
    case 'd':
        my_put_nbr(va_arg(arg, int));
        return 0 + n;
    case 'i':
        my_put_nbr(va_arg(arg, int));
        return 0 + n;
    case 'c':
        my_putchar(va_arg(arg, int));
        return 0 + n;
    case 'S':
        my_printf_maj_s(va_arg(arg, char *));
        return 0 + n;
    default:
        return my_printf_display_arg2(format, n, arg);
    }
}

void my_printf_maj_s(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isprintable(str[i]) == 0) {
            my_putchar('\\');
            print_in_octal3(str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
}
