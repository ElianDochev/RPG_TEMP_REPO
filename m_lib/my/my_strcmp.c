/*
** EPITECH PROJECT, 2022
** my_compute_power_it.c
** File description:
** power it
*/

#include "m_my.h"

bool is_same_str(char *str, char *compare)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != compare[i])
            return false;
        i++;
    }
    if (compare[i] != '\0')
        return false;
    return true;
}
