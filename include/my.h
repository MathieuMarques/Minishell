/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#include <stdarg.h>

#ifndef MY_H_

    #define MY_H_

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int is_number(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int test_sqr(int nb, int sqr);
void display_nbr(int nb);
int find_power(int nb);
char *put_upercase(char *str, int i);
char *put_upercase2(char *str, int i);
void first_nbr(char *dest, char const *str);
int first_nbr_len(char const *str);
int count_minus(char const *str);
int cond_minus(int nb_minus, int i, char const *str);
char *my_strdup(char *src);
int check_intr(char *str1, char *str2);
int check_dup(char *str);
int check_par(char *str);
int char_is_in_string(char c, char *str);
int check_unknown(char *expr, char *all_digits);
int check_h(int ac, char **av);
int my_printf(char *formats, ...);
int nbr_of_arg(char *formats);
int my_printf_display_arg(char *format, int n, va_list arg);
void my_printf_display(char *formats, va_list arg);
void print_in_octal3(char c);
char *int_to_str(int nb);
int my_char_isprintable(char c);
void my_printf_maj_s(char *str);
int get_octal_value(char c);
int my_printf_display_arg2(char *format, int n, va_list arg);
void print_binary(unsigned int nb);
int my_put_nbrl(long nb);
int my_put_nbrll(long long nb);
void print_in_hexa(unsigned int nb, char *base);
int find_power_malloc(unsigned int nb);
int my_printf_display_arg3(char *format, int n, va_list arg);
void print_in_octal(unsigned int nb);
unsigned int my_put_nbru(unsigned int nb);
int my_printf_display_arg4(char *format, int n, va_list arg);
int cond_arg(char *format, int n, va_list arg);
void print_maj_c(char c);

#endif
