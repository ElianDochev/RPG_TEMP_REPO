/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** cuting bush
*/

#include "main.h"
#include <stdio.h>

int is_aroud_player(player_t *player, int y, int x, char item)
{
    if (y > 0 && x > 0 && y < MAX_Y - 1 && x < MAX_X - 1) {
        if (player->direction == WLEFT && player->AT_LEFT == item)
            return WLEFT;
        if (player->direction == WRIGHT && player->AT_RIGHT == item)
            return WRIGHT;
        if (player->direction == WUP && player->AT_UP == item)
            return WUP;
        if (player->direction == WDOWN && player->AT_DOWN == item)
            return WDOWN;
    }
    return -1;
}

static void cut_the_bush(player_t *player, map_t *map, int y, int x)
{
    if (y > 0 && x > 0 && y < MAX_Y - 1 && x < MAX_X - 1) {
        if (player->direction == WLEFT) {
            player->AT_LEFT = ' ';
            map->AT_LEFT = 'b';
        }
        if (player->direction == WRIGHT) {
            player->AT_RIGHT = ' ';
            map->AT_RIGHT = 'b';
        }
        if (player->direction == WUP) {
            player->AT_UP = ' ';
            map->AT_UP = 'b';
        }
        if (player->direction == WDOWN) {
            player->AT_DOWN = ' ';
            map->AT_DOWN = 'b';
        }
    }
}

static int loop_player_cuting_bush(player_t *player, map_t *map, int y)
{
    for (int x = 0; x < MAX_X; ++x) {
        if (player->map[y][x] == 'B' && is_aroud_player(player, y, x, 'x')
        == player->direction && player->attack == 1) {
            cut_the_bush(player, map, y, x);
            player->money += 10;
            player->ruby = 1;
            return 1;
        }
    }
    return 0;
}

void player_cuting_bush(player_t *player, map_t *map)
{
    for (int y = 0; y < MAX_Y; ++y) {
        if (loop_player_cuting_bush(player, map, y) == 1)
            return;
    }
}
