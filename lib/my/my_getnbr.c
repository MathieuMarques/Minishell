/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** gets number in a string
*/

#include <stdio.h>

int my_compute_power_rec(int nb, int p);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_strlen(char const *str);
void first_nbr(char *dest, char const *str);
int first_nbr_len(char const *str);
int count_minus(char const *str);
int cond_minus(int nb_minus, int i, char const *str);

int my_getnbr(char const *str)
{
    int nb = 0;
    char nbr[first_nbr_len(str)];
    int n;
    int p = 0;
    first_nbr(nbr, str);
    my_revstr(nbr);
    for (int i = 0; nbr[i] != '\0'; i++) {
        nb = nb + (nbr[i] - 48) * my_compute_power_rec(10, p);
        p++;
    }
    nb = nb * my_compute_power_rec(-1, count_minus(str));
    return nb;
}

int first_nbr_len(char const *str)
{
    int n = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            n++;
        } else if (n != 0) {
            return n;
        }
    }
    return n;
}

void first_nbr(char *dest, char const *str)
{
    int n = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            dest[n] = str[i];
            n++;
        } else if (n != 0) {
            dest[n] = '\0';
            return;
        }
    }
    dest[n] = '\0';
    return;
}

int count_minus(char const *str)
{
    int nb_minus = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            nb_minus++;
        } else {
            nb_minus = cond_minus(nb_minus, i, str);
        }
    }
    return nb_minus;
}

int cond_minus(int nb_minus, int i, char const *str)
{
    if (str[i] >= '0' && str[i] <= '9') {
        return nb_minus;
    } else if (str[i] != '+' && str[i] != '-') {
        nb_minus = 0;
    } else {
        return nb_minus;
    }
    return nb_minus;
}
