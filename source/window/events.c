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
