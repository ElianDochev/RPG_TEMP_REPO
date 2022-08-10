/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** gets x and y  of the center of a window
*/

#include "main.h"

unsigned int get_center_y(sfRenderWindow *window)
{
    return (sfRenderWindow_getSize(window).y) / 2;
}

unsigned int get_center_x(sfRenderWindow *window)
{
    return (sfRenderWindow_getSize(window).x) / 2;
}

sfVector2u get_center_xy_pcn
(sfRenderWindow *window, float ofset_x, float ofset_y)
{
    sfVector2u vect = sfRenderWindow_getSize(window);

    vect.x =  vect.x / 2 + (ofset_x * vect.x);
    vect.y =  vect.y / 2 + (ofset_y * vect.y);
    return vect;
}

sfVector2u get_center_xy(sfRenderWindow *window, int offset_x, int offset_y)
{
    sfVector2u vect = sfRenderWindow_getSize(window);

    vect.x =  vect.x / 2 + offset_x;
    vect.y =  vect.y / 2 + offset_y;
    return vect;
}
