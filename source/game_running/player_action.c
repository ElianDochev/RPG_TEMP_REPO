/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** cuting bush
*/

#include "main.h"
#include <stdio.h>

int is_around_player(player_t *player, int y, int x, char item)
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

int is_around_ennemi(player_t *player, ennemi_t *ennemi, int y, int x,
char item)
{
    if (y > 0 && x > 0 && y < MAX_Y - 1 && x < MAX_X - 1) {
        if (ennemi->direction == WLEFT && player->AT_LEFT == item)
            return EWLEFT;
        if (ennemi->direction == WRIGHT && player->AT_RIGHT == item)
            return EWRIGHT;
        if (ennemi->direction == WUP && player->AT_UP == item)
            return EWUP;
        if (ennemi->direction == WDOWN && player->AT_DOWN == item)
            return EWDOWN;
    }
    return -1;
}

static void hit_ennemi(player_t *player, map_t *map, int y, int x)
{
    if (y > 0 && x > 0 && y < MAX_Y - 1 && x < MAX_X - 1) {
        if (player->direction == WLEFT)
            player->AT_LEFT = ' ';
        if (player->direction == WRIGHT)
            player->AT_RIGHT = ' ';
        if (player->direction == WUP)
            player->AT_UP = ' ';
        if (player->direction == WDOWN)
            player->AT_DOWN = ' ';
    }
}

static int loop_player_action(player_t *player, map_t *map, ennemi_t *ennemi,
int y)
{
    for (int x = 0; x < MAX_X; ++x) {
        if (player->map[y][x] == 'B' && is_around_player(player, y, x, 'E')
        == player->direction && player->attack == 1) {
            hit_ennemi(player, map, y, x);
            player->money += 10;
            player->ruby = 1;
            return 1;
        }
        if (player->map[y][x] == 'B' && is_around_player(player, y, x, 'x')
        == player->direction && player->attack == 1) {
            cut_the_bush(player, map, y, x);
            player->money += 1;
            player->ruby = 1;
            return 2;
        }
        if (player->map[y][x] == 'E' && is_around_ennemi(player, ennemi, y, x,
        'B') == ennemi->direction && player->attack == 0) {
            player->life--;
            return 3;
        }
    }
    return 0;
}

void player_action(player_t *player, map_t *map, ennemi_t *ennemi)
{
    for (int y = 0; y < MAX_Y; ++y) {
        if (loop_player_action(player, map, ennemi, y) != 0)
            return;
    }
}
