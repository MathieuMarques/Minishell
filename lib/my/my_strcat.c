/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** appends the src to the dest
*/

int my_strlen(char *str);

char *my_strcat(char *dest, char const *src)
{
    int length_dest;

    length_dest = my_strlen(dest);
    for (int i = 0; src[i] != '\0'; i++) {
        dest[length_dest + i] = src[i];
        if (src[i + 1] == '\0') {
            dest[length_dest + i + 1] = src[i + 1];
        }
    }
    return (dest);
}
