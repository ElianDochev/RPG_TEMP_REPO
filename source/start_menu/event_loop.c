/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event loop for the start menu
*/

#include "start_menu.h"

void ev_loop_start(states *state,
start_menu_elements_t *elements)
{
    sfEvent event;
    sfRenderWindow *window = elements->window;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
    }
}
