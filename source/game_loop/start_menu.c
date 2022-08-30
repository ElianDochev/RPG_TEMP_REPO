/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game loop for start menu
*/

#include "main.h"
#include "start_menu.h"
#include "buttons.h"
#include <stdio.h>

void start_menu(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    start_menu_elements_t *elements = init_start_elements(window, conf);

    sfText_setColor(elements->title->text, sfBlue);
    reset_global(global, conf->confs[conf_lives]);
    while (sfRenderWindow_isOpen(window) && *game_state == not_started) {
        ev_loop_start(window, game_state, elements->menu);
        sfRenderWindow_drawSprite(window, elements->background->sprite, NULL);
        sfRenderWindow_drawText(window, elements->title->text, NULL);
        draw_menu_bntext(elements->menu, window, 0, 100);
        set_cursor_to_mouse(elements->cursor, window);
        sfRenderWindow_display(window);
    }
    destroy_element(elements);
}
