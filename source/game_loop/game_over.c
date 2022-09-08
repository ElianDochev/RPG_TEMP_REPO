/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game over loop;
*/

#include "main.h"
#include "game_over.h"

//destroys the elements of the game over state
static void destroy_element(game_over_elements_t *elements,
time_mana_t *clock)
{
    destroy_text(elements->msg, 0);
    destroy_menu_bntext(elements->menu, 0);
    destroy_cursor(elements->cursor);
    sfFont_destroy(elements->main_font);
    sfMusic_destroy(elements->music);
    destroy_sprite(elements->background, DESTOY_TEXTURE);
    sfClock_destroy(clock->clock);
    free(clock);
    free(elements);
}

void game_over(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    game_over_elements_t *elements = init_gm_over_elements(window, conf);
    time_mana_t *clock = get_clock();

    while (sfRenderWindow_isOpen(window) && *game_state == gm_over) {
        clock->time = sfClock_getElapsedTime(clock->clock);
        clock->millisec = sfTime_asMilliseconds(clock->time);
        ev_loop_gm_over(window, game_state, elements->menu);
        if (clock->millisec > conf->confs[refresh_rate_ov_st]) {
            sfRenderWindow_drawSprite(window, elements->background->sprite,
            NULL);
            sfRenderWindow_drawText(window, elements->msg->text, NULL);
            draw_menu_bntext(elements->menu, window);
            set_cursor_to_mouse(elements->cursor, window);
            sfRenderWindow_display(window);
            sfClock_restart(clock->clock);
        }
    }
    destroy_element(elements, clock);
}
