/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** texture function and init
*/

#include "sprites.h"

textures_t_old *init_texture(char const *path, sfVector2u const *dims)
{
    textures_t_old *texture = malloc(sizeof(textures_t_old));

    texture->texture = sfTexture_createFromFile(path, NULL);
    texture->sp_sheet_entities = dims;
    return texture;
}

textures_t_old **make_text_array(int start, int finish, char const **paths,
sfVector2u const *dim)
{
    textures_t_old **array = malloc((finish - start + 2) * sizeof(void *));

    for (int i = 0; i <= finish - start && (dim->x * dim->y != 0)
    ; ++i, ++paths, ++dim)
        array[i] = init_texture(*paths, dim);
    array[finish - start + 1] = NULL;
    return array;
}

sprite_t_old **set_sprites_dif(int number_of_sprites, textures_t_old **texture)
{
    sprite_t_old **sprites = malloc((number_of_sprites + 1)  * sizeof(sprite_t_old *));

    for (int i = 0; i < number_of_sprites && *texture != NULL; ++i) {
        sprites[i] = set_sprite(*texture);
        ++texture;
    }
    sprites[number_of_sprites] = NULL;
    return sprites;
}

void destroy_texture(textures_t_old *texture)
{
    texture->sp_sheet_entities = NULL;
    sfTexture_destroy(texture->texture);
    xfree((void **) &texture);
}

void destroy_text_array(textures_t_old **array)
{
    for (int i = 0; array[i] != NULL; ++array)
        destroy_texture(array[i]);
    xfree((void **) &array);
}
