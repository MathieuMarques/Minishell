/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** compare two strings
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int result;
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0' && n > 0; i++) {
        if (s1[i] != s2[i]) {
            result = s1[i] - s2[i];
            return (result);
        }
        n--;
    }
    return (0);
}
