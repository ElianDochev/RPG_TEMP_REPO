/*
** EPITECH PROJECT, 2022
** rip
** File description:
** ma fonction
*/

#include <stdbool.h>
#include <stdlib.h>
#include "m_my.h"

int countcharw(char *str, int i)
{
    int count = 0;

    while (is_not_delim(str[i]) && str[i] != '\0') {
        ++count;
        ++i;
    }
    return (count);
}

char *copy_in_board(int *cpy2, char *str, int *i)
{
    char *dest = NULL;

    *cpy2 = countcharw(str, *i);
    dest = malloc(sizeof(char) * (*cpy2 + 1));
    dest[*cpy2] = '\0';
    *cpy2 = 0;
    return dest;
}

char **copy(char **dest, char *str, int words)
{
    int i = 0;
    int cpy1 = 0;
    int cpy2 = 0;

    while (cpy1 < words) {
        while (is_not_delim(str[i]) == false)
            ++i;
        if (is_not_delim(str[i]))
            dest[cpy1] = copy_in_board(&cpy2, str, &i);
        while (is_not_delim(str[i]) && str[i] != '\0') {
            dest[cpy1][cpy2] = str[i];
            ++i;
            ++cpy2;
        }
        if (is_not_delim(str[i]) == false || str[i] == '\0')
            ++cpy1;
        while (is_not_delim(str[i]) == false && str[i] != '\0')
            ++i;
    }
    return (dest);
}

int countword(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (is_not_delim(str[i])) {
            ++count;
            ++i;
        }
        while (is_not_delim(str[i]) && str[i] != '\0')
            ++i;
        ++i;
    }
    return (count);
}

char **my_str_to_word_array(char *str)
{
    int words = 0;
    char **dest = NULL;

    if (str == NULL)
        return NULL;
    words = countword(str);
    dest = malloc (sizeof(char *) * (words + 1));
    dest[words] = NULL;
    dest = copy(dest, str, words);
    return (dest);
}
