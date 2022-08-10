/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** Creates a sfInt rect object
*/

#include <SFML/Graphics.h>

sfIntRect create_int_rect(int left, int top, int heigth, int width)
{
    sfIntRect x = {left, top, heigth, width};

    return x;
}

sfFloatRect create_float_rect(float left, float top, float heigth, float width)
{
    sfFloatRect x = {left, top, heigth, width};

    return x;
}

sfFloatRect convert_from_int_rect(sfIntRect rect)
{
    sfFloatRect x = {(float) rect.left, (float) rect.top,
    (float) rect.height, (float) rect.width};

    return x;
}

sfIntRect convert_from_floar_rect(sfFloatRect rect)
{
    sfIntRect x = {(int) rect.left, (int) rect.top,
    (int) rect.height, (int) rect.width};

    return x;
}
