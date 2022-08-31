/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** button test .h
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "sprites.h"
    #define MAX_Y 16
    #define MAX_X 30
    #define TEXTURES_NB 12

enum {GROUND, WALL_UP, WALL_LEFT, WALL_DOWN, WALL_RIGHT, WALL_NO, WALL_SO,
WALL_SE, WALL_NE, BUSH, GRASS, TREE};
static const char TEXT_CHARS[] = " -(_)/oe\\xga";
static const char *PATHS_NAME[] = {"tile_sets/ground_tile.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/bush_tile.png", "tile_sets/grass_tile.png",
"tile_sets/tree.png"};
static const int RECT[][4] = {{0, 16, 16, 0}, {0, 16, 16, 16}, {16, 16, 16, 0},
{32, 16, 16, 16}, {16, 16, 16, 32}, {0, 16, 16, 0}, {32, 16, 16, 0},
{32, 16, 16, 32}, {0, 16, 16, 32}, {0, 16, 16, 0}, {0, 16, 16, 0},
{0, 80, 64, 0}};

typedef struct map
{
    char **map;
    sfTexture **textures;
    sprite_t ***sprites;
} map_t;

map_t *create_map(char *path);
void walls_textures_mana(sfTexture **textures);
sprite_t *choose_wall_texture(int y, int x, map_t *map);

#endif
