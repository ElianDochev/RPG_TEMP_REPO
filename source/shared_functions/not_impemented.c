/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function that is use whem you have not implemented a
*/

#include "main.h"
#include "buttons.h"

static void local_ev_loop(sfRenderWindow *window, button_text_t **menu,
int *running)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        for (int i = 0; menu[i]; ++i)
            loop_menu(menu[i], running, event, window);
    }
}

static void go_back(void *ptr)
{
    *(int *)ptr = 0;
}

static void destroy_things(text_t *title, button_text_t **menu,
sfFont *font)
{
    destroy_text(title);
    destroy_menu_bntext(menu);
    //destroy_cursor(cursor);
    sfFont_destroy(font);
}

void not_imp(void *ptr)
{
    sfFont *font = sfFont_createFromFile(MSG_FONT_HELP);
    int running = 1;
    sfRenderWindow *window = ( sfRenderWindow *) ptr;
    sfVector2f vect = con_vu_to_vf(get_center_xy_pcn(window, -0.08f, -0.05f));
    text_t *title = init_text(N_IMP_MSG, font, 30 , &vect);
    void (*action[])(void *) = {&go_back};
    button_text_t **menu = set_up_menu_bntext(font,
    create_fvector(vect.x, vect.y + 150), n_imp_button, action);
    //cursor_t *cursor = set_up_cursor(N_IMP_PATH_CURSOR);

    while (sfRenderWindow_isOpen(window) && running) {
        local_ev_loop(window, menu, &running);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, title->text, NULL);
        draw_menu_bntext(menu, window, 0, 0);
        //set_cursor_to_mouse(cursor, window);
        sfRenderWindow_display(window);
    }
    destroy_things(title, menu, font);
}
