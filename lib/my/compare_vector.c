/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** compares vectors
*/

#include "utilities.h"

int comp_fvector(sfVector2f *vect_one, sfVector2f *vect_two)
{
    if (vect_one->x == vect_two->x)
        if (vect_one->y == vect_two->y)
            return 1;
    return 0;
}

int comp_ivector(sfVector2i *vect_one, sfVector2i *vect_two)
{
    if (vect_one->x == vect_two->x)
        if (vect_one->y == vect_two->y)
            return 1;
    return 0;
}

int comp_uvector(sfVector2u *vect_one, sfVector2u *vect_two)
{
    if (vect_one->x == vect_two->x)
        if (vect_one->y == vect_two->y)
            return 1;
    return 0;
}
