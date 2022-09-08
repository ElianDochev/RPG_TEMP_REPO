/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Game_running loop
*/

#include "main.h"
#include <stdio.h>

void attack(player_t *player, time_mana_t *hit, sfRenderWindow *window)
{
    static int i = 0;
    sfVector2f pos = sfSprite_getPosition(player->
    sprites[player->direction]->sprite);
    sfIntRect *rect = get_int_rect(PLAYER_RECT[player->direction + 4][0],
    PLAYER_RECT[player->direction + 4][1], PLAYER_RECT[player->
    direction + 4][2], PLAYER_RECT[player->direction + 4][2] * i);

    hit->time = sfClock_getElapsedTime(hit->clock);
    hit->millisec = sfTime_asMilliseconds(hit->time);
    player->textures[player->direction + 4] = sfTexture_createFromFile(
    PLAYER_PATHS_NAME[player->direction + 4], NULL);
    player->sprites[player->direction + 4] = set_sprite(player->textures[
    player->direction + 4], NULL, rect, get_sfvector2f(2, 2));
    sfSprite_setPosition(player->sprites[player->direction + 4]->sprite, pos);
    sfRenderWindow_drawSprite(window, player->
    sprites[player->direction + 4]->sprite, NULL);
    if (hit->millisec >= 40) {
        ++i;
        sfClock_restart(hit->clock);
    }
    if (i >= 5) {
        i = 0;
        player->attack = 0;
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
    NULL, rect, get_sfvector2f(2, 2));
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

void game_running(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    int i = 0;
    int j = 0;
    time_mana_t *clock = get_clock();
    time_mana_t *pl = get_clock();
    time_mana_t *mo = get_clock();
    time_mana_t *hit = get_clock();
    time_mana_t *bom = get_clock();

    while (sfRenderWindow_isOpen(window) && *game_state == running) {
        clock->time = sfClock_getElapsedTime(clock->clock);
        clock->millisec = sfTime_asMilliseconds(clock->time);
        pl->time = sfClock_getElapsedTime(pl->clock);
        pl->millisec = sfTime_asMilliseconds(pl->time);
        ev_loop_running(window, game_state, global);
        sfRenderWindow_clear(window, sfBlack);
        if (clock->millisec > 350) {
            anim_flowers(global->map, &i);
            sfClock_restart(clock->clock);
        }
        if (pl->millisec > 30) {
            if (global->player->move == 1)
                anim_player(global->player, &j);
            sfClock_restart(pl->clock);
        }
        draw_map(window, global->map);
        if (global->player->bomb == 1)
            bomb(global->player, bom, window);
        if (global->player->attack == 1)
            attack(global->player, hit, window);
        else
            draw_player(window, global->player);
        if (move_player(global->player, mo) == 1)
            sfClock_restart(mo->clock);
        sfRenderWindow_display(window);
    }
}
