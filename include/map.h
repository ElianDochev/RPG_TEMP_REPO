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
    #define TEXTURES_NB 20

enum {GROUND, WALL_UP, WALL_LEFT, WALL_DOWN, WALL_RIGHT, WALL_NO, WALL_SO,
WALL_SE, WALL_NE, BUSH, GRASS, TREE, ROCK, SIGN, FLOWER, PLANT, PATH, CHEST,
OPEN_CHEST, HOUSE};
static const char TEXT_CHARS[] = " -(_)/oe\\xgtrSfp=cCH";
static const char *PATHS_NAME[] = {"tile_sets/ground_tile.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/bush_tile.png", "tile_sets/grass_tile.png",
"tile_sets/tree.png", "tile_sets/rock_tile.png", "tile_sets/sign.png",
"tile_sets/flower.png", "tile_sets/plant.png", "tile_sets/path_tile.png",
"tile_sets/Chest.png", "tile_sets/open_chest.png", "tile_sets/house.png"};
static const int RECT[][4] = {{0, 16, 16, 0}, {0, 16, 16, 16}, {16, 16, 16, 0},
{32, 16, 16, 16}, {16, 16, 16, 32}, {0, 16, 16, 0}, {32, 16, 16, 0},
{32, 16, 16, 32}, {0, 16, 16, 32}, {0, 16, 16, 0}, {0, 16, 16, 0},
{0, 80, 64, 0}, {0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 0},
{0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 16}, {0, 64, 96, 0}};

typedef struct map
{
    char **map;
    sfTexture **textures;
    sprite_t **sprites;
} map_t;

map_t *create_map(char *path);
void walls_textures_mana(sfTexture **textures);
sprite_t *choose_wall_texture(int y, int x, map_t *map);

#endif
