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
    player->direction + 4], NULL, rect, get_sfvector2f(1.5, 1.5));
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

void game_running(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    int i = 0;
    int j = 0;
    time_mana_t *clock = get_clock();
    time_mana_t *pl = get_clock();
    time_mana_t *mo = get_clock();
    time_mana_t *hit = get_clock();

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
        if (global->player->attack == 1)
            attack(global->player, hit, window); //!!!!! Utiliser l'attaque que en direction gauche sinon sex fault !!!!!!//
        else
            draw_player(window, global->player);
        if (move_player(global->player, mo) == 1)
            sfClock_restart(mo->clock);
        sfRenderWindow_display(window);
    }
}
