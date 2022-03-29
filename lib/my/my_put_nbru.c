/*
** EPITECH PROJECT, 2021
** my_put_nbru
** File description:
** displays the given number
*/

void my_putchar(char c);

unsigned int find_poweru(unsigned int nb);

void display_nbru(unsigned int nb);

unsigned int my_put_nbru(unsigned int nb)
{
    if (nb < 0) {
        my_putchar('-');
        display_nbru(-nb);
    } else if (nb > 0) {
        display_nbru(nb);
    } else {
        my_putchar('0');
    }
    return (0);
}

unsigned int find_poweru(unsigned int nb)
{
    unsigned int i;
    i = 1;
    while (i - 1 < nb / 10) {
        i = i * 10;
    }
    return (i);
}

void display_nbru(unsigned int nb)
{
    unsigned int i;
    unsigned int nb_disp;
    i = find_poweru(nb);
    while (i >= 1) {
        nb_disp = nb / i;
        my_putchar(nb_disp + 48);
        nb = nb - (nb_disp * i);
        i = i / 10;
    }
}
