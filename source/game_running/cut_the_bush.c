/*
** EPITECH PROJECT, 2022
** cut_the_bush.c
** File description:
** cut_the_bush.c
*/

#include "main.h"

void cut_the_bush(player_t *player, map_t *map, int y, int x)
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
