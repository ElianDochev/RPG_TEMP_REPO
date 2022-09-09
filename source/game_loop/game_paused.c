/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game paused loop
*/

#include "game_paused.h"

void game_paused(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    game_paused_elements_t *elements = init_paused_elements(window, conf,
    global);
    time_mana_t *clock = get_clock();

    while (sfRenderWindow_isOpen(window) && *game_state == paused) {
        ev_loop_paused(window, game_state);
        clock->time = sfClock_getElapsedTime(clock->clock);
        clock->millisec = sfTime_asMilliseconds(clock->time);
        if (clock->millisec > conf->confs[refresh_rate_ov_st]) {
            draw_map(window, global->map);
            draw_player(window, global->player);
            sfRenderWindow_drawRectangleShape(window,
            elements->square_container, NULL);
            draw_menu_bntext(elements->menu, window, game_state, elements);
            set_cursor_to_mouse(elements->cursor, window);
            sfRenderWindow_display(window);
            sfClock_restart(clock->clock);
        }
    }
}
