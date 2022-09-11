/*
** EPITECH PROJECT, 2022
** Utility fucntion
** File description:
** returns the lenth of a string/ copies the content of one string to another
*/

#include "utilities.h"
#include <stdlib.h>

int my_strlen(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        ++len;
    }
    return len;
}

char *str_dup(char *scr)
{
    int len = my_strlen(scr);
    char *dest = malloc(len + 1);

    for (int i = 0; i <= len; ++i)
        dest[i] = scr[i];
    return dest;
}

void str_copy(char *dest, char *scr)
{
    int len = my_strlen(scr);

    for (int i = 0; i <= len; ++i)
        dest[i] = scr[i];
}

void empty_buffer(char *str, int size)
{
    for (int i = 0; i < size; ++i)
        str[i] = '\0';
}

int two_d_arr_len(char **arr)
{
    int count = 0;

    while (*arr) {
        ++count;
        ++arr;
    }
    return count;
}
