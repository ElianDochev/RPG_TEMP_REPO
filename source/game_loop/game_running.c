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
    time_mana_t clock;

    clock.clock = sfClock_create();
    while (sfRenderWindow_isOpen(window) && *game_state == running) {
        clock.time = sfClock_getElapsedTime(clock.clock);
        clock.millisec = sfTime_asMilliseconds(clock.time);
        ev_loop_running(window, game_state);
        sfRenderWindow_clear(window, sfBlack);
        if (clock.millisec > 300) {
            anim_flowers(global->map, &i);
            sfClock_restart(clock.clock);
        }
        draw_map(window, global->map);
        sfRenderWindow_display(window);
    }
}
