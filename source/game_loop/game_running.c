/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Game_running loop
*/

#include "main.h"
#include <stdio.h>

void attack(player_t *p, time_mana_t *hit, sfRenderWindow *window)
{
    static int i = 0;
    sfVector2f pos = sfSprite_getPosition(p->sprites[p->direction]->sprite);
    sfIntRect *rect = get_int_rect(PLAYER_RECT[p->direction + 4][0],
    PLAYER_RECT[p->direction + 4][1], PLAYER_RECT[p->direction + 4][2],
    PLAYER_RECT[p->direction + 4][2] * i);

    hit->time = sfClock_getElapsedTime(hit->clock);
    hit->millisec = sfTime_asMilliseconds(hit->time);
    p->textures[p->direction + 4] = sfTexture_createFromFile(
    PLAYER_PATHS_NAME[p->direction + 4], NULL);
    p->sprites[p->direction + 4] = set_sprite(p->textures[p->direction + 4],
    NULL, rect, get_sfvector2f(2, 2));
    sfSprite_setPosition(p->sprites[p->direction + 4]->sprite, pos);
    sfRenderWindow_drawSprite(window, p->sprites[p->direction + 4]->sprite,
    NULL);
    if (hit->millisec >= 40) {
        ++i;
        sfClock_restart(hit->clock);
    }
    if (i >= 5) {
        i = 0;
        p->attack = 0;
    }
}

void bomb(player_t *player, time_mana_t *bom, sfRenderWindow *window)
{
    static int i = 0;
    sfVector2f pos;
    sfIntRect *rect = get_int_rect(PLAYER_RECT[BOMB][0], PLAYER_RECT[BOMB][1],
    PLAYER_RECT[BOMB][2], PLAYER_RECT[BOMB][2] * i);

    if (i == 0)
        pos = sfSprite_getPosition(player->sprites[player->direction]->sprite);
    else
        pos = sfSprite_getPosition(player->sprites[BOMB]->sprite);
    bom->time = sfClock_getElapsedTime(bom->clock);
    bom->millisec = sfTime_asMilliseconds(bom->time);
    player->textures[BOMB] = sfTexture_createFromFile(PLAYER_PATHS_NAME[BOMB],
    NULL);
    player->sprites[BOMB] = set_sprite(player->textures[BOMB],
    NULL, rect, get_sfvector2f(2.5, 2.5));
    sfSprite_setPosition(player->sprites[BOMB]->sprite, pos);
    sfRenderWindow_drawSprite(window, player->sprites[BOMB]->sprite, NULL);
    if (bom->millisec >= 90) {
        ++i;
        sfClock_restart(bom->clock);
    }
    if (i >= 18) {
        i = 0;
        player->bomb = 0;
    }
}

int choose_map(player_t *player, int y, int x)
{
    if (player->map[y][x + 1] >= '0' && player->map[y][x + 1] <= '9')
        return player->map[y][x + 1] - '0';
    if (player->map[y][x - 1] >= '0' && player->map[y][x - 1] <= '9')
        return player->map[y][x - 1] - '0';
    if (player->map[y + 1][x] >= '0' && player->map[y + 1][x] <= '9')
        return player->map[y + 1][x] - '0';
    if (player->map[y - 1][x] >= '0' && player->map[y - 1][x] <= '9')
        return player->map[y - 1][x] - '0';
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

void game_running(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    time_mana_t *fl = get_clock();
    time_mana_t *pl = get_clock();
    time_mana_t *mo = get_clock();
    time_mana_t *hit = get_clock();
    time_mana_t *bom = get_clock();

    while (sfRenderWindow_isOpen(window) && *game_state == running) {
        sfRenderWindow_clear(window, sfBlack);
        ev_loop_running(window, game_state, global);
        draw_map(window, global->map);
        anim_flowers(global->map, fl);
        if (global->player->move == 1 && global->player->attack != 1)
            anim_player(global->player, pl);
        if (global->player->bomb == 1)
            bomb(global->player, bom, window);
        if (global->player->attack == 1 && global->player->move != 1)
            attack(global->player, hit, window);
        else
            draw_player(window, global->player);
        if (move_player(global->player, mo) == 1)
            sfClock_restart(mo->clock);
        draw_ennemi(window, global);
        which_map(window, global->player, global->map);
        sfRenderWindow_display(window);
    }
}
