/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** convert vectors type
*/

#include "utilities.h"

sfVector2f con_vi_to_vf(sfVector2i vector)
{
    sfVector2f new = {.x = (float) vector.x, .y = (float) vector.y};

    return new;
}

sfVector2f con_vu_to_vf(sfVector2u vector)
{
    sfVector2f new = {.x = (float) vector.x, .y = (float) vector.y};

    return new;
}
