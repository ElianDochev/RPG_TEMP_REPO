/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** Calculates the power of a int rec
*/

#include "utilities.h"

int calc_pow(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    return nb * calc_pow(nb, p - 1);
}
