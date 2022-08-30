/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game over loop;
*/

#include "main.h"
#include "game_over.h"

static void destroy_stuff(sfFont *font, text_t *msg,
button_text_t **menu)//,cursor_t *cursor)
{
    destroy_text(msg);
    destroy_menu_bntext(menu);
    //destroy_cursor(cursor);
    sfFont_destroy(font);
}

void game_over(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    sfFont *font = sfFont_createFromFile(conf->paths[start_font]);
    sfVector2f vect = con_vu_to_vf(get_center_xy_pcn(window, -0.05 , -0.2));
    text_t *msg = init_text(str_join_free(gm_over_msg[global->win],
    int_to_str(global->score)), font, 50 , &vect);
    void (*action[])(void *) = {&start_over, &quit};
    button_text_t **menu = set_up_menu_bntext(font, create_fvector
    (vect.x - 100, vect.y + 200), gm_over_menu, action);
   // cursor_t *cursor = set_up_cursor(conf->paths[cursor_path]);

    while (sfRenderWindow_isOpen(window) && *game_state == gm_over) {
        sfRenderWindow_clear(window, sfBlack);
        ev_loop_gm_over(window, game_state, menu);
        sfRenderWindow_drawText(window, msg->text, NULL);
        draw_menu_bntext(menu, window, 300, 0);
        //set_cursor_to_mouse(cursor, window);
        sfRenderWindow_display(window);
    }
    destroy_stuff(font, msg, menu);//, cursor);
}
