/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game loop for start menu
*/

#include "main.h"
#include "start_menu.h"
#include "buttons.h"

//destroys the elements of the start menu
static void destroy_element(start_menu_elements_t *elements,
time_mana_t *clock)
{
    destroy_text(elements->title, 0);
    destroy_menu_bntext(elements->menu, 0);
    destroy_cursor(elements->cursor);
    sfFont_destroy(elements->main_font);
    sfMusic_destroy(elements->music);
    destroy_sprite(elements->background, DESTOY_TEXTURE);
    sfClock_destroy(clock->clock);
    free(clock);
    free(elements);
}

void set_values(sfVector2f vect, config_t *conf, start_menu_elements_t *elements)
{
    if (vect.x != 0)
        conf->confs[sound_vol_cf] = vect.x;
    conf->confs[music_vol_cf] = (int) sfMusic_getVolume(elements->music);
}

void start_menu(sfRenderWindow *w, states *game_state,
global_t *global, config_t *conf)
{
    start_menu_elements_t *elements = init_start_elements(w, conf);
    time_mana_t *clock = get_clock();

    elements->vect = (sfVector2f) {0, 0};
    reset_global(global, conf->confs[conf_lives]);
    while (sfRenderWindow_isOpen(w) && *game_state == not_started) {
        clock->time = sfClock_getElapsedTime(clock->clock);
        clock->millisec = sfTime_asMilliseconds(clock->time);
        ev_loop_start(game_state, elements);
        if (clock->millisec > conf->confs[refresh_rate_ov_st]) {
            sfRenderWindow_drawSprite(w, elements->background->sprite, NULL);
            sfRenderWindow_drawText(w, elements->title->text, NULL);
            draw_menu_bntext(elements->menu, w, game_state, elements);
            set_cursor_to_mouse(elements->cursor, w);
            sfRenderWindow_display(w);
            sfClock_restart(clock->clock);
        }
    }
    set_values(elements->vect, conf, elements);
    destroy_element(elements, clock);
}
