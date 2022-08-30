/*
** EPITECH PROJECT, 2022
** my_compute_power_it.c
** File description:
** power it
*/

#include <stdio.h>
#include <stdlib.h>
#include "m_my.h"

char *concat_str(char *base, char *next)
{
    int size = my_strlen(base) + my_strlen(next);
    char *new = malloc(sizeof(char) * size + 1);
    int temp = 0;

    for (int i = 0; i < size; i++) {
        if (base[i] != '\0' && temp == 0)
            new[i] = base[i];
        else if (temp != 0)
            new[i] = next[i - temp];
        else {
            new[i] = next[0];
            temp = i;
        }
    }
    new[size] = '\0';
    return new;
}
