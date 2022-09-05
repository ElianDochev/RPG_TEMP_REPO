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
    #define TEXTURES_NB 23

enum {OUT_HOUSE, FIRST_PATH, BATTLE_PATH};
static const char *MAP_PATHS[] = {"maps/out_house_.front",
"maps/first_path.front", "maps/battle_path.front"};
enum {GROUND, WALL_UP, WALL_LEFT, WALL_DOWN, WALL_RIGHT, WALL_NO, WALL_SO,
WALL_SE, WALL_NE, BUSH, CUT_BUSH, GRASS, TREE, ROCK, SIGN, FLOWER, PLANT,
PATH, CHEST, OPEN_CHEST, HOUSE, HOUSE_TILE, MOVABLE_ROCK};
static const char TEXT_CHARS[] = " -(_)/oe\\xbgtrSfp=cCHhR";
static const char *TILES_PATHS[] = {"tile_sets/ground_tile.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/bush_tile.png", "tile_sets/bush_tile.png",
"tile_sets/grass_tile.png", "tile_sets/tree.png", "tile_sets/rock_tile.png",
"tile_sets/sign.png", "tile_sets/flower.png", "tile_sets/plant.png",
"tile_sets/path_tile.png", "tile_sets/chest.png", "tile_sets/chest.png",
"tile_sets/house.png", "tile_sets/house_tile.png",
"tile_sets/movable_rock.png"};
static const int RECT[][4] = {{0, 16, 16, 0}, {0, 16, 16, 16}, {16, 16, 16, 0},
{32, 16, 16, 16}, {16, 16, 16, 32}, {0, 16, 16, 0}, {32, 16, 16, 0},
{32, 16, 16, 32}, {0, 16, 16, 32}, {0, 16, 16, 0}, {0, 16, 16, 16},
{0, 16, 16, 0}, {0, 80, 64, 0}, {0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 0},
{0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 16}, {0, 96, 96, 0},
{0, 16, 16, 0}, {0, 16, 16, 0}};

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
