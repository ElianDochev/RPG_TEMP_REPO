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
    destroy_text(elements->title);
    destroy_menu_bntext(elements->menu);
    destroy_cursor(elements->cursor);
    sfFont_destroy(elements->main_font);
    sfMusic_destroy(elements->music);
    destroy_sprite(elements->background, DESTOY_TEXTURE);
    sfClock_destroy(clock->clock);
    free(clock);
    free(elements);
}

void start_menu(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    start_menu_elements_t *elements = init_start_elements(window, conf);
    time_mana_t *clock = get_clock();

    reset_global(global, conf->confs[conf_lives]);
    while (sfRenderWindow_isOpen(window) && *game_state == not_started) {
        clock->time = sfClock_getElapsedTime(clock->clock);
        clock->millisec = sfTime_asMilliseconds(clock->time);
        ev_loop_start(game_state, elements);
        if (clock->millisec > conf->confs[refresh_rate_ov_st]) {
            sfRenderWindow_drawSprite(window, elements->background->sprite, NULL);
            sfRenderWindow_drawText(window, elements->title->text, NULL);
            draw_menu_bntext(elements->menu, window);
            set_cursor_to_mouse(elements->cursor, window);
            sfRenderWindow_display(window);
            sfClock_restart(clock->clock);
        }
    }
    destroy_element(elements, clock);
}
