/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** recursive function that returns the number raised by the power
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p == 0) {
        result = 1;
    } else if (p < 0) {
        result = 0;
    } else {
        result = nb * my_compute_power_rec(nb, p - 1);
    }
    return (result);
}
