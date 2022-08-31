/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game over loop;
*/

#include "main.h"
#include "game_over.h"

//destroys the elements of the game over state
static void destroy_element(game_over_elements_t *elements)
{
    destroy_text(elements->msg);
    destroy_menu_bntext(elements->menu);
    destroy_cursor(elements->cursor);
    sfFont_destroy(elements->main_font);
    sfMusic_destroy(elements->music);
    destroy_sprite(elements->background, DESTOY_TEXTURE);
    free(elements);
}


void game_over(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    game_over_elements_t *elements = init_gm_over_elements(window, conf);

    while (sfRenderWindow_isOpen(window) && *game_state == gm_over) {
        sfRenderWindow_drawSprite(window, elements->background->sprite, NULL);
        ev_loop_gm_over(window, game_state, elements->menu);
        sfRenderWindow_drawText(window, elements->msg->text, NULL);
        draw_menu_bntext(elements->menu, window, 300, 0);
        set_cursor_to_mouse(elements->cursor, window);
        sfRenderWindow_display(window);
    }
    destroy_element(elements);
}
