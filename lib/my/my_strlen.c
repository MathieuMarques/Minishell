/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** returns the number of characetrs in a string
*/

int my_strlen(char const *str);

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
