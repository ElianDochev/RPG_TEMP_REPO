/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_ennemi
*/

#include "ennemi.h"
#include "m_my.h"
#include <fcntl.h>
#include <unistd.h>

static sprite_t **init_ennemi_sprites(ennemi_t *ennemi)
{
    sprite_t **sprites = malloc(sizeof(sprite_t *) * ENNEMI_TEXTURE_NB);

    for (int i = 0; i < ENNEMI_TEXTURE_NB; i++)
        sprites[i] = set_sprite(ennemi->textures[i], NULL, NULL,
        get_sfvector2f(1.5, 1.5));
    return sprites;
}

static sfTexture **init_ennemi_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * ENNEMI_TEXTURE_NB);

    for (int i = 0; i < ENNEMI_TEXTURE_NB; i++)
        textures[i] = sfTexture_createFromFile(ENNEMI_PATHS_NAME[i],
        get_int_rect(ENNEMI_RECT[i][0], ENNEMI_RECT[i][1],
        ENNEMI_RECT[i][2], ENNEMI_RECT[i][3]));
    for (int i = 0; i < ENNEMI_TEXTURE_NB; i++)
        if (textures[i] != NULL)
            sfTexture_setSmooth(textures[i], sfTrue);
    return textures;
}

ennemi_t *set_up_ennemi(void)
{
    ennemi_t *ennemi = malloc(sizeof(ennemi_t));

    if (ennemi == NULL)
        return NULL;
    ennemi->textures = init_ennemi_textures();
    ennemi->sprites = init_ennemi_sprites(ennemi);
    ennemi->direction = 0;
    ennemi->move = 0;
    return ennemi;
}
