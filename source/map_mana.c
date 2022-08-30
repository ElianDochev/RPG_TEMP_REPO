/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_maps
*/

#include "map.h"
#include "m_my.h"

void draw_map(sfRenderWindow *window, map_t *map)
{
    sfVector2f pos = create_fvector(0, 0);

    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            sfSprite_setPosition(map->sprites[y][x]->sprite, pos);
            sfRenderWindow_drawSprite(window, map->sprites[y][x]->sprite, NULL);
            pos.x += 16;
        }
        pos.x = 0;
        pos.y += 16;
    }
}