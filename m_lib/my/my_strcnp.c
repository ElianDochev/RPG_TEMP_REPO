/*
** EPITECH PROJECT, 2022
** my_compute_power_it.c
** File description:
** power it
*/

#include "m_my.h"

bool is_same_part_str(char *str, char *compare, int n)
{
    for (int i = 0; i < n; i++)
        if (str[i] == '\0' || str[i] != compare[i])
            return false;
    return true;
}
