/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_maps
*/

#include "map.h"
#include "m_my.h"

void destroy_map(map_t *map)
{
    for (int y = 0; y < MAX_Y; y++)
        free(map->map[y]);
    free(map->sprites);
    free(map->textures);
    free(map->map);
}

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

static void draw_sprite(map_t *map, char c, sfVector2f *pos,
sfRenderWindow *window)
{
    for (int i = 0; i < TEXTURES_NB; i++)
        if (c == TEXT_CHARS[i]) {
            sfSprite_setPosition(map->sprites[i]->sprite, *pos);
            sfRenderWindow_drawSprite(window, map->sprites[i]->sprite, NULL);
        }
}

static void draw_special_sprite(map_t *map, char c, sfVector2f *pos,
sfRenderWindow *window)
{
    for (int i = 0; i < TEXTURES_NB; i++) {
        if (c == TEXT_CHARS[i] && is_in_special(i)) {
            sfSprite_setPosition(map->sprites[i]->sprite, *pos);
            sfRenderWindow_drawSprite(window, map->sprites[i]->sprite, NULL);
        }
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
            draw_special_sprite(map, map->map[y][x], &pos, window);
            pos.x += 64;
        }
        pos.x = 0;
        pos.y += 64;
    }
}
