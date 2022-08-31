/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_maps
*/

#include "map.h"
#include "m_my.h"

void walls_textures_mana(sfTexture **textures)
{
    textures[WALL_LEFT_TEXT] = sfTexture_createFromFile(
    "tile_sets/wall_tiles.png", get_int_rect(16, 16, 16, 0));
    textures[WALL_DOWN_TEXT] = sfTexture_createFromFile(
    "tile_sets/wall_tiles.png", get_int_rect(32, 16, 16, 16));
    textures[WALL_RIGHT_TEXT] = sfTexture_createFromFile(
    "tile_sets/wall_tiles.png", get_int_rect(16, 16, 16, 32));
    textures[WALL_UP_TEXT] = sfTexture_createFromFile(
    "tile_sets/wall_tiles.png", get_int_rect(0, 16, 16, 16));
    textures[WALL_NO_TEXT] = sfTexture_createFromFile(
    "tile_sets/wall_tiles.png", get_int_rect(0, 16, 16, 0));
    textures[WALL_NE_TEXT] = sfTexture_createFromFile(
    "tile_sets/wall_tiles.png", get_int_rect(0, 16, 16, 32));
    textures[WALL_SE_TEXT] = sfTexture_createFromFile(
    "tile_sets/wall_tiles.png", get_int_rect(32, 16, 16, 32));
    textures[WALL_SO_TEXT] = sfTexture_createFromFile(
    "tile_sets/wall_tiles.png", get_int_rect(32, 16, 16, 0));
}

sprite_t *choose_wall_texture(int y, int x, map_t *map)
{
    if (map->map[y][x] == WALL_LEFT)
        return set_sprite(map->textures[WALL_LEFT_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    if (map->map[y][x] == WALL_RIGHT)
        return set_sprite(map->textures[WALL_RIGHT_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    if (map->map[y][x] == WALL_UP)
        return set_sprite(map->textures[WALL_UP_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    if (map->map[y][x] == WALL_NO)
        return set_sprite(map->textures[WALL_NO_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    if (map->map[y][x] == WALL_DOWN)
        return set_sprite(map->textures[WALL_DOWN_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
   if (map->map[y][x] == WALL_NE)
        return set_sprite(map->textures[WALL_NE_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
   if (map->map[y][x] == WALL_SO)
        return set_sprite(map->textures[WALL_SO_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
   if (map->map[y][x] == WALL_SE)
        return set_sprite(map->textures[WALL_SE_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    return NULL;
}
