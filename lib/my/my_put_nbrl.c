/*
** EPITECH PROJECT, 2021
** my_put_nbrl
** File description:
** displays the given number long
*/

void my_putchar(char c);

long find_powerl(long nb);

void display_nbrl(long nb);

int my_put_nbrl(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        display_nbrl(-nb);
    } else if (nb > 0) {
        display_nbrl(nb);
    } else {
        my_putchar('0');
    }
    return (0);
}

long find_powerl(long nb)
{
    long i;
    i = 1;
    while (i - 1 < nb / 10) {
        i = i * 10;
    }
    return (i);
}

void display_nbrl(long nb)
{
    long i;
    long nb_disp;
    i = find_powerl(nb);
    while (i >= 1) {
        nb_disp = nb / i;
        my_putchar(nb_disp + 48);
        nb = nb - (nb_disp * i);
        i = i / 10;
    }
}
