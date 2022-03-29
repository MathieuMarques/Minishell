/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** copies n characters from a string into another
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n && i < my_strlen(src); i++) {
        dest[i] = src[i];
    }
    if (n > my_strlen(src)) {
        dest[my_strlen(src)] = '\0';
    }
    return (dest);
}
