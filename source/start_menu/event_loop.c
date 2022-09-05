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
        for (int i = 0; (elements->menu)[i]; ++i)
            (i == 0 || ((elements->menu)[i + 1] == NULL)) ?
            loop_menu((elements->menu)[i], state, event, window) :
            loop_menu((elements->menu[i]), elements, event, window);
    }
}
