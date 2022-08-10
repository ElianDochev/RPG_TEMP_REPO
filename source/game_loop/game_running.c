/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Game_running loop
*/

#include "main.h"

void game_running(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    while (sfRenderWindow_isOpen(window) && *game_state == running) {
        ev_loop_running(window, game_state);
        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_display(window);
    }
}
