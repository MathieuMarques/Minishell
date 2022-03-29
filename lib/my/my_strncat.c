/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** appends n characters from a string into another
*/

int my_strlen(char *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int length_dest;

    length_dest = my_strlen(dest);
    for (int i = 0; src[i] != '\0' && i < nb; i++) {
        dest[length_dest + i] = src[i];
        if (src[i + 1] == '\0') {
            dest[length_dest + i + 1] = src[i + 1];
        }
    }
    return (dest);
}
