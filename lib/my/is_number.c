/*
** EPITECH PROJECT, 2021
** is_number.c
** File description:
** is_number
*/

int is_number(char const *str)
{
    int cond = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        cond = (str[i] == '-' || str[i] == '+') && i == 0;
        if (!((str[i] >= '0' && str[i] <= '9') || cond))
            return 0;
    }
    return 1;
}
