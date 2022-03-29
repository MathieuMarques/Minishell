/*
** EPITECH PROJECT, 2022
** str_to_tab.c
** File description:
** str_to_tab
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int size_tab(char *str)
{
    int count = 0;
    int s_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            count++;
            s_count = 0;
        }
        if (str[i] == ' ' && str[i] != '\t' && s_count == 0) {
            s_count++;
            count++;
        }
    }
    count++;
    return count;
}

int size_word(char *str, int id)
{
    int count = 0;
    for (int i = id; str[i] != ' ' && str[i] != '\0' && str[i] != '\t'; i++) {
        count++;
    }
    return count;
}

void str_to_char2(char *str, int id, char **tab, int index)
{
    int count = 0;
    tab[index] = malloc((size_word(str, id) + 1) * sizeof(char));
    for (int i = id; str[i] != ' ' && str[i] != '\0' && str[i] != '\n' &&
                    str[i] != '\t'; i++) {
        tab[index][count] = str[i];
        count++;
    }
    tab[index][count] = '\0';
}

char **str_to_tab(char *str)
{
    char **tab = malloc((size_tab(str)) * sizeof(char *) + sizeof(NULL));
    if (tab == NULL)
        return NULL;
    int index = 0;
    for (int i = 0; str[i] != '\0';) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            str_to_char2(str, i, tab, index);
            i += size_word(str, i);
            index++;
        } else
            i++;
    }
    tab[index] = malloc(sizeof(char));
    tab[index] = NULL;
    return tab;
}
