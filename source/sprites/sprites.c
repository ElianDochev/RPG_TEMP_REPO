/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** sprites sprite
*/

#include "sprites.h"

sprite_t_old *set_sprite(textures_t_old *texture)
{
    sprite_t_old *sprite = malloc(sizeof(sprite_t_old));
    sfVector2u v = sfTexture_getSize(texture->texture);
    sfVector2f vf = texture->sp_sheet_entities != NULL ?
    create_fvector((float) v.x / texture->sp_sheet_entities->x, (float) v.y /
    texture->sp_sheet_entities->y) : create_fvector(1, 1);

    sprite->sprite = sfSprite_create();
    sprite->texture = texture;
    sfSprite_setTexture(sprite->sprite, sprite->texture->texture, sfTrue);
    sfSprite_setScale(sprite->sprite, create_fvector((float) v.x / vf.x,
    (float) v.y / vf.y));
    return sprite;
}

sprite_t_old **set_sprites_same(int number_of_sprites, textures_t_old *texture)
{
    sprite_t_old **sprites = malloc((number_of_sprites + 1)  * sizeof(void *));

    for (int i = 0; i < number_of_sprites; ++i)
        sprites[i] = set_sprite(texture);
    sprites[number_of_sprites] = NULL;
    return sprites;
}

void set_position(sprite_t_old *sprite, int row, int colon)
{
    sfVector2u vector = sfTexture_getSize(sprite->texture->texture);

    vector.x /= sprite->texture->sp_sheet_entities->x;
    vector.y /= sprite->texture->sp_sheet_entities->y;
    sfSprite_setTextureRect(sprite->sprite,
    create_int_rect(vector.x * (row - 1), vector.y * (colon - 1),
    vector.y, vector.x));
}

void destroy_sprite(sprite_t_old *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sprite->texture = NULL;
    xfree((void **) &sprite);
}

void destroy_array_sprites(sprite_t_old **sprites)
{
    for (int i = 0; sprites[i] != NULL; ++i)
        destroy_sprite(*sprites);
    xfree((void **) &sprites);
}
