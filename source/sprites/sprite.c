/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** sprite creation
*/

#include "sprites.h"

sprite_t *set_sprite(sfTexture *texture, char *path, sfIntRect *rect,
sfVector2f *scale_vector)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->rect = rect;
    sprite->sprite = sfSprite_create();
    sprite->texture = texture == NULL ? sfTexture_createFromFile(path, NULL) :
    texture;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    if (rect != NULL)
        sfSprite_setTextureRect(sprite->sprite, *rect);
    if (scale_vector != NULL)
        sfSprite_setScale(sprite->sprite, *scale_vector);
    sfTexture_setSmooth(sprite->texture, sfTrue);
    return sprite;
}
