/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Game_running loop
*/

#include "main.h"
#include <stdio.h>

int choose_map(player_t *player, int y, int x)
{
    if (player->move == 1) {
        if (player->map[y][x + 1] >= '0' && player->map[y][x + 1] <= '9' &&
        player->direction == WRIGHT)
            return player->map[y][x + 1] - '0';
        if (player->map[y][x - 1] >= '0' && player->map[y][x - 1] <= '9' &&
        player->direction == WLEFT)
            return player->map[y][x - 1] - '0';
        if (player->map[y + 1][x] >= '0' && player->map[y + 1][x] <= '9' &&
        player->direction == WDOWN)
            return player->map[y + 1][x] - '0';
        if (player->map[y - 1][x] >= '0' && player->map[y - 1][x] <= '9' &&
        player->direction == WUP)
            return player->map[y - 1][x] - '0';
    }
    return -1;
}

void change_map_back(player_t *player, const char *path)
{
    char *buffer = get_map(path);

    if (buffer == NULL) {
        write(2, "Invalid path or map can't change map\n", 38);
        return;
    }
    free_board(player->map);
    player->map = my_str_to_word_array(buffer);
}

void put_player_map(player_t *player, int intmap)
{
    if (intmap == OUT_HOUSE && player->nbr_map == FIRST_PATH) {
        player->map[7][13] = ' ';
        player->map[11][27] = 'B';
    }
    if (intmap == FIRST_PATH && player->nbr_map == BATTLE_PATH) {
        player->map[12][2] = ' ';
        player->map[2][16] = 'B';
    }
    if (intmap == BATTLE_PATH && player->nbr_map == SANCTUARY_ENTRY) {
        player->map[13][15] = ' ';
        player->map[2][15] = 'B';
    }
}

void which_map(sfRenderWindow *window, player_t *player, map_t *map)
{
    int intmap = 0;

    for (int y = 0; y < MAX_Y; ++y) {
        for (int x = 0; x < MAX_X; ++x) {
            if (player->map[y][x] == 'B') {
                if ((intmap = choose_map(player, y, x)) != -1) {
                    change_map(map, MAP_PATHS[intmap]);
                    change_map_back(player, PLAYER_MAP_PATHS[intmap]);
                    put_player_map(player, intmap);
                    player->nbr_map = intmap;
                    return;
                }
            }
        }
    }
}