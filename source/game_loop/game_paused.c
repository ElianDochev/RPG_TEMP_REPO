/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game paused loop
*/

#include "main.h"

void game_paused(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    while (sfRenderWindow_isOpen(window) && *game_state == paused) {
        ev_loop_paused(window, game_state);
        sfRenderWindow_clear(window, sfYellow);
        sfRenderWindow_display(window);
    }
}
