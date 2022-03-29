/*
** EPITECH PROJECT, 2021
** my_char_isprintable.c
** File description:
** return 1 if the char is printable
*/

int my_char_isprintable(char c)
{
    if (c < ' ')
        return 0;
    else if (c >= 127)
        return 0;
    else
        return 1;
}
