/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** Joins two strings into one
*/

#include "utilities.h"
#include <stdlib.h>

char *str_join_free(char const *str_one, char *str_two)
{
    int length_str_one = my_strlen(str_one);
    int length_str_two = my_strlen(str_two);
    char *new_str = malloc(length_str_one + length_str_two + 1);

    for (int i = 0; i < length_str_one; i++)
        new_str[i] = str_one[i];
    for ( int i = 0; i < length_str_two; i++)
        new_str[length_str_one + i] = str_two[i];
    new_str[length_str_one + length_str_two] = '\0';
    xfree((void **) &str_two);
    return new_str;
}

char *str_join(char const *str_one, char *str_two)
{
    int length_str_one = my_strlen(str_one);
    int length_str_two = my_strlen(str_two);
    char *new_str = malloc(length_str_one + length_str_two + 1);

    for (int i = 0; i < length_str_one; i++)
        new_str[i] = str_one[i];
    for ( int i = 0; i < length_str_two; i++)
        new_str[length_str_one + i] = str_two[i];
    new_str[length_str_one + length_str_two] = '\0';
    return new_str;
}
