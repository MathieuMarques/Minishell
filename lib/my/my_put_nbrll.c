/*
** EPITECH PROJECT, 2021
** my_put_nbrl
** File description:
** displays the given number long
*/

void my_putchar(char c);

long find_powerll(long long nb);

void display_nbrll(long long nb);

int my_put_nbrll(long long nb)
{
    if (nb < 0) {
        my_putchar('-');
        display_nbrll(-nb);
    } else if (nb > 0) {
        display_nbrll(nb);
    } else {
        my_putchar('0');
    }
    return (0);
}

long find_powerll(long long nb)
{
    long long i;
    i = 1;
    while (i - 1 < nb / 10) {
        i = i * 10;
    }
    return (i);
}

void display_nbrll(long long nb)
{
    long long i;
    long long nb_disp;
    i = find_powerll(nb);
    while (i >= 1) {
        nb_disp = nb / i;
        my_putchar(nb_disp + 48);
        nb = nb - (nb_disp * i);
        i = i / 10;
    }
}
