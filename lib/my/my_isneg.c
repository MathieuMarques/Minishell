/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** test if the number is negative or positive
*/

int my_putchar(char c);

int my_isneg(int n);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar(80);
    } else {
        my_putchar(78);
    }
}
