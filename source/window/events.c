/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** Event handeling and interations
*/

#include <stdlib.h>
#include "main.h"
#include "buttons.h"

void ev_loop_paused(sfRenderWindow *window, states *state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyP)) {
            *state == running ? *state = paused :
            *state == paused ? *state = running : 0;
        }
    }
}

void ev_loop_running(sfRenderWindow *window, states *state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyP)) {
            *state == running ? *state = paused :
            *state == paused ? *state = running : 0;
        }
    }
}

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

void ev_loop_start(sfRenderWindow *window, states *state, button_text_t **menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        for (int i = 0; menu[i]; ++i)
            (i == 0 || (menu[i + 1] == NULL)) ?
            loop_menu(menu[i], state, event, window) :
            loop_menu_window(menu[i], state, event, window);
    }
}

void event_loop(sfRenderWindow *window, states *state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
    }
}
