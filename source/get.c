/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_maps
*/

#include "map.h"

sfIntRect *get_int_rect(int top, int height, int width, int left)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = top;
    rect->height = height;
    rect->width = width;
    rect->left = left;
    return rect;
}

sfVector2f *get_sfvector2f(int y, int x)
{
    sfVector2f *vector = malloc(sizeof(sfVector2f));

    vector->y = y;
    vector->x = x;
    return vector;
}
