/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event loop for game over
*/

#include "game_over.h"

void ev_loop_gm_over(sfRenderWindow *window, states *state,
button_text_t **menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        for (int i = 0; menu[i]; ++i) {
            loop_menu(menu[i], state, event, window);
        }
    }
}
