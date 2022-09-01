/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_maps
*/

#include "map.h"
#include "main.h"

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

time_mana_t *get_clock(void)
{
    time_mana_t *clock = malloc(sizeof(time_mana_t));

    clock->clock = sfClock_create();
    clock->millisec = 0;
    return clock;
}
