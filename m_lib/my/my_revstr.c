/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** function that reverse a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char *rev = malloc(sizeof(char) * (my_strlen(str)));
    int j = (my_strlen(str) - 1);

    if (rev == NULL)
        return NULL;
    for (int i = 0; i <= j; i++)
        rev[i] = str[j - i];
    return rev;
}
