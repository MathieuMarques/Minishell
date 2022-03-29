/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** capitalizes the first letter of each word
*/

char *my_strlowcase(char *str);

char *put_upercase(char *str, int i);

char *put_upercase2(char *str, int i);

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            put_upercase(str, i);
        }
    }
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }
    return (str);
}

char *put_upercase(char *str, int i)
{
    if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z')) {
        if (!(str[i - 1] >= '0' && str[i - 1] <= '9')) {
            put_upercase2(str, i);
        }
    }
    return (str);
}

char *put_upercase2(char *str, int i)
{
    if (!(str[i - 1] >= 'A' && str[i - 1] <= 'Z')) {
        str[i] = str[i] - 32;
    }
    return (str);
}
