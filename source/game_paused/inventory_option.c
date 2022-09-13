/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** the open inventory function
*/

#include "game_paused.h"

static void local_event_loop(sfRenderWindow *window, int *running)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyP))
            *running = 0;
    }
}

void open_inventory(void *arg, int index)
{
    game_paused_elements_t *elements = (game_paused_elements_t *) arg;
    sfRectangleShape *cont = sfRectangleShape_create();
    int running = 1;

    not_imp(elements->window);
    // sfRectangleShape_setPosition(cont, (sfVector2f){50, 50});
    // sfRectangleShape_setSize(cont, create_fvector(
    // (sfRenderWindow_getSize(elements->window).x - 100),
    // (sfRenderWindow_getSize(elements->window).y - 100)));
    // sfRectangleShape_setFillColor(cont, sfBlue);
    // sfRectangleShape_setOutlineColor(cont, sfColor_fromRGB(0xff, 0xaf, 0x7a));
    // sfRectangleShape_setOutlineThickness(cont, 5);
    // while (running && sfRenderWindow_isOpen(elements->window)) {
    //     local_event_loop(elements->window, &running);
    //     draw_map(elements->window, elements->global->map);
    //     draw_player(elements->window, elements->global->player);
    //     draw_ennemi(elements->window, elements->global);
    //     sfRenderWindow_drawRectangleShape(elements->window, cont, NULL);
    //     set_cursor_to_mouse(elements->cursor, elements->window);
    //     sfRenderWindow_display(elements->window);
    // }
}
