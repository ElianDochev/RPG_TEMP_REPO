/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_maps
*/

#include "map.h"

typedef struct sprite
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rect;
} sprite_t;

sprite_t *set_sprite(char *path, sfIntRect *rect, sfVector2f *scale_vector)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->rect = rect;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    if (rect != NULL)
        sfSprite_setTextureRect(sprite->sprite, *rect);
    if (scale_vector != NULL)
        sfSprite_setScale(sprite->sprite, *scale_vector);
    sfTexture_setSmooth(sprite->texture, sfTrue);
    return sprite;
}

