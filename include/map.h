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
    #define TEXTURES_NB 29

enum {OUT_HOUSE, FIRST_PATH, BATTLE_PATH, HOUSE_INTERIOR_MAP, SANCTUARY_ENTRY};
static const char *MAP_PATHS[] = {"maps/out_house.front",
"maps/first_path.front", "maps/battle_path.front", "maps/house_interior.front",
"maps/sanctuary_entry.front"};
enum {GROUND, WALL_UP, WALL_LEFT, WALL_DOWN, WALL_RIGHT, WALL_NO, WALL_SO,
WALL_SE, WALL_NE, BUSH, CUT_BUSH, GRASS, TREE, ROCK, SIGN, FLOWER, PLANT,
PATH, CHEST, OPEN_CHEST, HOUSE, HOUSE_INTERIOR, MOVABLE_ROCK, NEUTRAL_TILE,
SANCTUARY, FENCE, PORTAL_LEFT, PORTAL_RIGHT, BORDER_FENCE};
static const char TEXT_CHARS[] = " -(_)/oe\\xbgtrsfp=cCHhRnSF;:.";
static const char *TILES_PATHS[] = {"tile_sets/ground_tile.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/wall_tiles.png", "tile_sets/wall_tiles.png",
"tile_sets/bush_tile.png", "tile_sets/bush_tile.png",
"tile_sets/grass_tile.png", "tile_sets/tree.png", "tile_sets/rock_tile.png",
"tile_sets/sign.png", "tile_sets/flower.png", "tile_sets/plant.png",
"tile_sets/path_tile.png", "tile_sets/chest.png", "tile_sets/chest.png",
"tile_sets/house.png", "tile_sets/house_interior.png",
"tile_sets/movable_rock.png", "tile_sets/house_unseen.png",
"tile_sets/sanctuary_entry.png", "tile_sets/fence.png",
"tile_sets/left_portal.png", "tile_sets/right_portal.png",
"tile_sets/border_fence.png"};
static const int RECT[][4] = {{0, 16, 16, 0}, {0, 16, 16, 16}, {16, 16, 16, 0},
{32, 16, 16, 16}, {16, 16, 16, 32}, {0, 16, 16, 0}, {32, 16, 16, 0},
{32, 16, 16, 32}, {0, 16, 16, 32}, {0, 16, 16, 0}, {0, 16, 16, 16},
{0, 16, 16, 0}, {0, 80, 64, 0}, {0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 0},
{0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 16}, {0, 96, 96, 0},
{0, 176, 224, 0}, {0, 16, 16, 0}, {0, 16, 16, 0}, {0, 95, 128, 0},
{0, 16, 16, 0}, {0, 24, 16, 0}, {0, 24, 16, 0}, {0, 32, 16, 0}};
#define SPECIALS__NB 7
static const int SPECIALS[] = {TREE, HOUSE, HOUSE_INTERIOR, SANCTUARY,
PORTAL_LEFT, PORTAL_RIGHT, BORDER_FENCE};

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
