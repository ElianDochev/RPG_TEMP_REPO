/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** button test .h
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <stdbool.h>
    #include "sprites.h"
    #define MAX_Y 16
    #define MAX_X 30
    #define TEXTURES_NB 34

enum {OUT_HOUSE, FIRST_PATH, BATTLE_PATH, HOUSE_INTERIOR_MAP, SANCTUARY_ENTRY,
SHOP_INTERIOR_MAP, DUNGEON_ENTRY_MAP, SOKOBAN_MAP, OUT_SHOP};
static const char *MAP_PATHS[] = {"maps/out_house.front",
"maps/first_path.front", "maps/battle_path.front", "maps/house_interior.front",
"maps/sanctuary_entry.front", "maps/shop_interior.front",
"maps/dungeon_entry.front", "maps/sokoban_puzzle.front",
"maps/out_house.front"};
enum {GROUND, WALL_UP, WALL_LEFT, WALL_DOWN, WALL_RIGHT, WALL_NO, WALL_SO,
WALL_SE, WALL_NE, BUSH, CUT_BUSH, GRASS, TREE, ROCK, SIGN, FLOWER, PLANT,
PATH, CHEST, OPEN_CHEST, HOUSE, HOUSE_INTERIOR, MOVABLE_ROCK, NEUTRAL_TILE,
SANCTUARY, FENCE, PORTAL_LEFT, PORTAL_RIGHT, BORDER_FENCE, SHOP_INTERIOR,
DUNGEON_ENTRY, DUNGEON_UNSEEN_TILE, SOKOBAN_ROOM, PRESSABLE_TILE};
static const char TEXT_CHARS[] = " -(_)/oe\\xbgtrsfp=cCHhRnSF;:.$&NmO";
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
"tile_sets/border_fence.png", "tile_sets/shop_interior.png",
"tile_sets/dungeon_entry.png", "tile_sets/Dungeon_unseen_tile.png",
"tile_sets/sokoban_room.png", "tile_sets/pressable_tile.png"};
static const int RECT[][4] = {{0, 16, 16, 0}, {0, 16, 16, 16}, {16, 16, 16, 0},
{32, 16, 16, 16}, {16, 16, 16, 32}, {0, 16, 16, 0}, {32, 16, 16, 0},
{32, 16, 16, 32}, {0, 16, 16, 32}, {0, 16, 16, 0}, {0, 16, 16, 16},
{0, 16, 16, 0}, {0, 80, 64, 0}, {0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 0},
{0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 0}, {0, 16, 16, 16}, {0, 96, 105, 0},
{0, 176, 232, 0}, {0, 16, 16, 0}, {0, 16, 16, 0}, {0, 95, 128, 0},
{0, 16, 16, 0}, {0, 24, 16, 0}, {0, 24, 16, 0}, {0, 32, 16, 0},
{0, 176, 200, 0}, {0, 237, 257, 0}, {0, 16, 16, 0}, {0, 237, 257, 0},
{0, 16, 16, 0}};
#define SPECIALS_NB 12
static const int SPECIALS[] = {TREE, HOUSE, HOUSE_INTERIOR, SANCTUARY,
PORTAL_LEFT, PORTAL_RIGHT, BORDER_FENCE, SHOP_INTERIOR, DUNGEON_ENTRY,
MOVABLE_ROCK, SOKOBAN_ROOM, PRESSABLE_TILE};

typedef struct map
{
    char **map;
    sfTexture **textures;
    sprite_t **sprites;
} map_t;

map_t *create_map(const char *path);
void walls_textures_mana(sfTexture **textures);
sprite_t *choose_wall_texture(int y, int x, map_t *map);
//returns true if nb is in the array SPECIALS[]
bool is_in_special(int nb);

#endif
