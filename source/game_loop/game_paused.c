/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game paused loop
*/

#include "game_paused.h"

void destroy_game_paused_elements(game_paused_elements_t *elements,
time_mana_t *clock)
{
    if (elements->vect.x != 0)
        elements->conf->confs[sound_vol_cf] = elements->vect.x;
    elements->conf->confs[music_vol_cf] =
    (int) sfMusic_getVolume(elements->music);
    destroy_menu_bntext(elements->menu, 0);
    sfRectangleShape_destroy(elements->square_container);
    sfFont_destroy(elements->main_font);
    sfClock_destroy(clock->clock);
    sfMusic_destroy(elements->music);
    xfree((void **) &clock);
    destroy_cursor(elements->cursor);
    xfree((void **) &elements);
}

void game_paused(sfRenderWindow *w, states *game_state,
global_t *global, config_t *conf)
{
    game_paused_elements_t *elem = init_paused_elements(w, conf, global);
    time_mana_t *clock = get_clock();

    elem->vect = (sfVector2f) {0, 0};
    while (sfRenderWindow_isOpen(w) && *game_state == paused) {
        ev_loop_paused(w, game_state);
        clock->time = sfClock_getElapsedTime(clock->clock);
        clock->millisec = sfTime_asMilliseconds(clock->time);
        if (clock->millisec > conf->confs[refresh_rate_ov_st]) {
            draw_map(w, global->map);
            draw_player(w, global->player);
            draw_ennemi(w, global);
            sfRenderWindow_drawRectangleShape(w, elem->square_container, NULL);
            draw_menu_bntext(elem->menu, w, game_state, elem);
            set_cursor_to_mouse(elem->cursor, w);
            sfRenderWindow_display(w);
            sfClock_restart(clock->clock);
        }
    }
    destroy_game_paused_elements(elem, clock);
}
