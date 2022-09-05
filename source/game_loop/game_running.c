/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Game_running loop
*/

#include "main.h"
#include <stdio.h>

void game_running(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    int i = 0;
    int j = 0;
    time_mana_t *clock = get_clock();
    time_mana_t *pl = get_clock();
    time_mana_t *mo = get_clock();

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
        draw_player(window, global->player);
        if (move_player(global->player, mo) == 1)
            sfClock_restart(mo->clock);
        sfRenderWindow_display(window);
    }
}
