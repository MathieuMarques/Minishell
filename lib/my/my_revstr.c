/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverses a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char char1;
    char char2;

    for (int i = 0; i != my_strlen(str) / 2; i++) {
        char1 = str[i];
        char2 = str[my_strlen(str) - i - 1];
        str[i] = char2;
        str[my_strlen(str) - i - 1] = char1;
    }
    return (str);
}
