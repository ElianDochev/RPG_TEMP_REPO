/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** cange map
*/

#include "main.h"
#include <stdio.h>
#include <unistd.h>

static int choose_map(player_t *player, int y, int x)
{
    if (player->move == 1) {
        if (player->AT_RIGHT >= '0' && player->AT_RIGHT <= '9' &&
        player->direction == WRIGHT)
            return player->map[y][x + 1] - '0';
        if (player->AT_LEFT >= '0' && player->AT_LEFT <= '9' &&
        player->direction == WLEFT)
            return player->map[y][x - 1] - '0';
        if (player->AT_DOWN >= '0' && player->AT_DOWN <= '9' &&
        player->direction == WDOWN)
            return player->map[y + 1][x] - '0';
        if (player->AT_UP >= '0' && player->AT_UP <= '9' &&
        player->direction == WUP)
            return player->map[y - 1][x] - '0';
    }
    return -1;
}

static void change_map_back(player_t *player, const char *path)
{
    char *buffer = get_map(path);

    if (buffer == NULL) {
        write(2, "Invalid path or map can't change map\n", 38);
        return;
    }
    free_board(player->map);
    player->map = my_str_to_word_array(buffer);
}

static int loop_which_map(player_t *player, map_t *map, int intmap, int y)
{
    for (int x = 0; x < MAX_X; ++x) {
        if (player->map[y][x] == 'B' && (intmap = choose_map(player, y, x))
        != -1) {
            change_map(map, MAP_PATHS[intmap]);
            change_map_back(player, PLAYER_MAP_PATHS[intmap]);
            put_player_map(player, intmap);
            player->nbr_map = intmap;
            return 1;
        }
    }
    return 0;
}

void which_map(player_t *player, map_t *map)
{
    int intmap = 0;

    for (int y = 0; y < MAX_Y; ++y) {
        if (loop_which_map(player, map, intmap, y) == 1)
            return;
    }
}
