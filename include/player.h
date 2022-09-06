/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** player.h
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include "sprites.h"
    #define MAX_Y 16
    #define MAX_X 30
    #define PLAYER_TEXTURE_NB 9

enum {WLEFT, WRIGHT, WUP, WDOWN, HLEFT, HRIGHT, HUP, HDOWN, BOMB};
static const char PLAYER_TEXT_CHARS[] = "B";
static const char *PLAYER_PATHS_NAME[] = {"tile_sets/player_walk_left.png",
"tile_sets/player_walk_right.png", "tile_sets/player_walk_up.png",
"tile_sets/player_walk_down.png", "tile_sets/player_hit_left.png",
"tile_sets/player_hit_right.png", "tile_sets/player_hit_up.png",
"tile_sets/player_hit_down.png", "tile_sets/bomb_explosion.png"};
static const int PLAYER_RECT[][5] = {{0, 48, 48, 0}, {0, 48, 48, 0},
{0, 48, 48, 0}, {0, 48, 48, 0}, {0, 48, 48, 0}, {0, 48, 48, 0}, {0, 48, 48, 0},
{0, 48, 48, 0}, {0, 48, 48, 0}};

typedef struct player {
    char **map;
    sfTexture **textures;
    sprite_t **sprites;
    int direction;
    int attack;
    int bomb;
    int move;
} player_t;

player_t *set_up_player(void);
char *get_map(char *path);
void draw_player(sfRenderWindow *window, player_t *player);
void anim_player(player_t *player, int *j);

#endif
