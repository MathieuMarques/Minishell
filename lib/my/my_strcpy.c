/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copies a string into another
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[my_strlen(src)] = '\0';
    return (dest);
}
