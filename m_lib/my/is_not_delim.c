/*
** EPITECH PROJECT, 2022
** rip
** File description:
** ma fonction
*/

#include <stdbool.h>

bool is_not_delim(char c)
{
    if (c == '\n')
        return false;
    return true;
}
