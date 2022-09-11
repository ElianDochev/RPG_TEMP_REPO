/*
** EPITECH PROJECT, 2022
** put_player.c
** File description:
** put_player.c
*/

#include "main.h"

static void put_player_map_first(player_t *player, int intmap)
{
    if (intmap == OUT_HOUSE && player->nbr_map == FIRST_PATH) {
        player->map[6][14] = ' ';
        player->map[11][28] = 'B';
    }
    if (intmap == FIRST_PATH && player->nbr_map == BATTLE_PATH) {
        player->map[12][1] = ' ';
        player->map[2][16] = 'B';
    }
    if (intmap == BATTLE_PATH && player->nbr_map == SANCTUARY_ENTRY) {
        player->map[14][15] = ' ';
        player->map[1][15] = 'B';
    }
    if (intmap == SANCTUARY_ENTRY && player->nbr_map == DUNGEON_ENTRY_MAP) {
        player->map[13][15] = ' ';
        player->map[4][14] = 'B';
    }
}

void put_player_map(player_t *player, int intmap)
{
    put_player_map_first(player, intmap);
    if (intmap == DUNGEON_ENTRY_MAP && player->nbr_map == SOKOBAN_MAP) {
        player->map[11][14] = ' ';
        player->map[7][20] = 'B';
    }
    if (intmap == SANCTUARY_ENTRY && player->nbr_map == OUT_SHOP) {
        player->map[13][15] = ' ';
        player->map[7][1] = 'B';
    }
    if (intmap == OUT_SHOP && player->nbr_map == SHOP_INTERIOR_MAP) {
        player->map[7][28] = ' ';
        player->map[5][4] = 'B';
    }
    if (intmap == DUNGEON_ENTRY_MAP && player->nbr_map == MAZE) {
        player->map[11][14] = ' ';
        player->map[7][8] = 'B';
    }
}
