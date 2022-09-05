/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_maps
*/

#include "map.h"
#include "m_my.h"

void anim_flowers(map_t *map, int *i)
{
    map->textures[FLOWER] = sfTexture_createFromFile(TILES_PATHS[FLOWER],
    get_int_rect(RECT[FLOWER][0], RECT[FLOWER][1], RECT[FLOWER][2],
    RECT[FLOWER][3] + (RECT[FLOWER][2] * *i)));
    map->sprites[FLOWER] = set_sprite(map->textures[FLOWER], NULL, NULL,
    get_sfvector2f(4, 4));
    ++*i;
    if (*i > 2)
        *i = 0;
}

void draw_sprite(map_t *map, char c, sfVector2f *pos, sfRenderWindow *window)
{
    for (int i = 0; i < TEXTURES_NB; i++)
        if (c == TEXT_CHARS[i]) {
            sfSprite_setPosition(map->sprites[i]->sprite, *pos);
            sfRenderWindow_drawSprite(window, map->sprites[i]->sprite, NULL);
        }
}

void draw_object_sprite(map_t *map, char c, sfVector2f *pos,
sfRenderWindow *window)
{
    if (c == TEXT_CHARS[HOUSE]) {
        sfSprite_setPosition(map->sprites[HOUSE]->sprite, *pos);
        sfRenderWindow_drawSprite(window, map->sprites[HOUSE]->sprite, NULL);
    }
    if (c == TEXT_CHARS[TREE]) {
        sfSprite_setPosition(map->sprites[TREE]->sprite, *pos);
        sfRenderWindow_drawSprite(window, map->sprites[TREE]->sprite, NULL);
    }
}

void draw_map(sfRenderWindow *window, map_t *map)
{
    sfVector2f pos = create_fvector(0, 0);

    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            draw_sprite(map, map->map[y][x], &pos, window);
            pos.x += 64;
        }
        pos.x = 0;
        pos.y += 64;
    }
    pos.y = 0;
    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            draw_object_sprite(map, map->map[y][x], &pos, window);
            pos.x += 64;
        }
        pos.x = 0;
        pos.y += 64;
    }
}
