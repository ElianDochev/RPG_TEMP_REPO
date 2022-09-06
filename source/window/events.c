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

void event_move_player(global_t *global, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        global->player->direction = 0;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        global->player->direction = 1;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        global->player->direction = 2;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        global->player->direction = 3;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
        global->player->attack = 1;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyB)
        global->player->bomb = 1;
}

void ev_loop_running(sfRenderWindow *window, states *state, global_t *global)
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
        if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown))
            global->player->move = 1;
        else
            global->player->move = 0;
        event_move_player(global, event);
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
