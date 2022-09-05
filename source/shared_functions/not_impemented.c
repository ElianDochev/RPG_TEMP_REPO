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
sfFont *font, cursor_t *cursor)
{
    destroy_text(title, 0);
    destroy_menu_bntext(menu, 0);
    destroy_cursor(cursor);
    sfFont_destroy(font);
}

static void display_things(sfRenderWindow *window, text_t *title,
button_text_t **menu, cursor_t *cursor)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, title->text, NULL);
    draw_menu_bntext(menu, window);
    set_cursor_to_mouse(cursor, window);
    sfRenderWindow_display(window);
}

void not_imp(void *ptr)
{
    sfFont *font = sfFont_createFromFile(MSG_FONT_HELP);
    int running = 1;
    void *color[] = {&sfWhite, &sfBlue, &sfGreen};
    sfRenderWindow *window = ( sfRenderWindow *) ptr;
    sfVector2f vect = con_vu_to_vf(get_center_xy_pcn(window, -0.08f, -0.05f));
    text_t *title = init_text(N_IMP_MSG, font, 30 , &vect);
    void (*action[])(void *) = {&go_back};
    button_text_t **menu = set_up_menu_bntext(font,
    init_button_text_info(create_fvector(vect.x, vect.y + 150), color,
    create_fvector(0, 0), 40), n_imp_button, action);
    cursor_t *cursor = set_up_cursor(N_IMP_PATH_CURSOR);

    sfText_setFillColor(title->text, sfRed);
    while (sfRenderWindow_isOpen(window) && running) {
        local_ev_loop(window, menu, &running);
        display_things(window, title, menu, cursor);
    }
    destroy_things(title, menu, font, cursor);
}
