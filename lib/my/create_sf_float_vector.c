/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** Creates a 2d vector of any type
*/

#include "utilities.h"

sfVector2f create_fvector(float x, float y)
{
    sfVector2f new = {.x = x, .y = y};

    return new;
}

sfVector2u create_uvector(unsigned int x, unsigned int y)
{
    sfVector2u new = {.x = x, .y = y};

    return new;
}

sfVector2i create_ivector(int x, int y)
{
    sfVector2i new = {.x = x, .y = y};

    return new;
}
