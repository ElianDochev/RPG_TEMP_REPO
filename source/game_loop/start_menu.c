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

static void destroy_things(text_t *title, button_text_t **menu,
sfFont *font, cursor_t *cursor)
{
    destroy_text(title);
    destroy_menu_bntext(menu);
    destroy_cursor(cursor);
    sfFont_destroy(font);
}

void start_menu(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    sfFont *font = sfFont_createFromFile(conf->paths[start_font]);
    sfVector2f vect = con_vu_to_vf(get_center_xy_pcn(window, -0.05f, -0.3f));
    text_t *title = init_text("my_rpg", font, 50 , &vect);
    void (*action[])(void *) = {&start, &not_imp, &not_imp, &quit};
    button_text_t **menu = set_up_menu_bntext(font,
    create_fvector(vect.x, vect.y + 100), options_msg, action);
    cursor_t *cursor = set_up_cursor(conf->paths[cursor_path]);

    sfText_setColor(title->text, sfBlue);
    reset_global(global, conf->confs[conf_lives]);
    while (sfRenderWindow_isOpen(window) && *game_state == not_started) {
        ev_loop_start(window, game_state, menu);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, title->text, NULL);
        draw_menu_bntext(menu, window, 0, 100);
        set_cursor_to_mouse(cursor, window);
        sfRenderWindow_display(window);
    }
    destroy_things(title, menu, font, cursor);
}
