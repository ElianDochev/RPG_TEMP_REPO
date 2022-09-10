/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** player.h
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include "sprites.h"
    #include "conf.h"

    #define MAX_Y 16
    #define MAX_X 30
    #define PLAYER_TEXTURE_NB 10
    #define AT_LEFT map[y][x - 1]
    #define AT_RIGHT map[y][x + 1]
    #define AT_UP map[y - 1][x]
    #define AT_DOWN map[y + 1][x]
    #define KEY_TOUCH event.type == sfEvtKeyPressed && event.key.code

static const char *PLAYER_MAP_PATHS[] = {"maps/out_house.back",
"maps/first_path.back", "maps/battle_path.back", "maps/house_interior.back",
"maps/sanctuary_entry.back", "maps/shop_interior.back",
"maps/dungeon_entry.back", "maps/sokoban_puzzle.back",
"maps/out_shop.back"};
enum {WLEFT, WRIGHT, WUP, WDOWN, HLEFT, HRIGHT, HUP, HDOWN, BOMB, RRUBY};
static const char PLAYER_TEXT_CHARS[] = "B";
static const char *PLAYER_PATHS_NAME[] = {"resources/link/player_walk_left.png",
"resources/link/player_walk_right.png", "resources/link/player_walk_up.png",
"resources/link/player_walk_down.png", "resources/link/player_hit_left.png",
"resources/link/player_hit_right.png", "resources/link/player_hit_up.png",
"resources/link/player_hit_down.png", "resources/link/bomb_explosion.png",
"resources/link/red_ruby.png"};
static const int PLAYER_RECT[][5] = {{0, 48, 48, 0}, {0, 48, 48, 0},
{0, 48, 48, 0}, {0, 48, 48, 0}, {0, 48, 48, 0}, {0, 48, 48, 0}, {0, 48, 48, 0},
{0, 48, 48, 0}, {0, 48, 48, 0}, {0, 62, 20, 0}};

typedef struct {
    int live;
    int attack;
    int defense;
    node_t *inventory;
} player_stats_t;

typedef struct player {
    char **map;
    sfTexture **textures;
    sprite_t **sprites;
    int direction;
    int attack;
    int bomb;
    int move;
    int nbr_map;
    int money;
    int ruby;
    player_stats_t *stats;
} player_t;
////////////////////////////////////////////////////////////
/// \brief Create a player object
///
/// \param path       path to the map file
/// \param conf       the confguration of the game for lives and stuff
///
/// \return returns the player object
///
///////////////////////////////////////////////////////////
player_t *set_up_player(char *path, config_t *conf);
char *get_map(const char *path);
void draw_player(sfRenderWindow *window, player_t *player);
int is_aroud_player(player_t *player, int y, int x, char item);

#endif

