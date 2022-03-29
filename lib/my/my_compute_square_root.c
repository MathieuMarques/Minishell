/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** returns the square root
*/

int my_compute_power_rec(int nb, int p);

int test_sqr(int nb, int sqr);

int my_compute_square_root(int nb)
{
    int result;

    result = test_sqr(nb, 0);
    return (result);
}

int test_sqr(int nb, int sqr)
{
    int sqr_p;

    sqr_p = my_compute_power_rec(sqr, 2);
    if (nb < sqr_p) {
        sqr = 0;
    } else if (nb > sqr_p) {
        sqr = test_sqr(nb, sqr + 1);
    }
    return (sqr);
}
