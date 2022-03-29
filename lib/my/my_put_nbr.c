/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** displays the given number
*/

void my_putchar(char c);

int find_power(int nb);

void display_nbr(int nb);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        display_nbr(-nb);
    } else if (nb > 0) {
        display_nbr(nb);
    } else {
        my_putchar('0');
    }
    return (0);
}

int find_power(int nb)
{
    int i;
    i = 1;
    while (i - 1 < nb / 10) {
        i = i * 10;
    }
    return (i);
}

void display_nbr(int nb)
{
    int i;
    int nb_disp;
    i = find_power(nb);
    while (i >= 1) {
        nb_disp = nb / i;
        my_putchar(nb_disp + 48);
        nb = nb - (nb_disp * i);
        i = i / 10;
    }
}
