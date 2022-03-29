/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** display characters
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}
