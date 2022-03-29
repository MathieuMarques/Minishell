/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** swaps the content of two integers
*/

void my_swap(int *a, int *b);

void my_swap(int *a, int *b)
{
    int sa;
    int sb;

    sa = *a;
    sb = *b;
    *a = sb;
    *b = sa;
}
