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
    if (KEY_TOUCH == sfKeyLeft)
        global->player->direction = WLEFT;
    if (KEY_TOUCH == sfKeyRight)
        global->player->direction = WRIGHT;
    if (KEY_TOUCH == sfKeyUp)
        global->player->direction = WUP;
    if (KEY_TOUCH == sfKeyDown)
        global->player->direction = WDOWN;
    if (KEY_TOUCH == sfKeySpace)
        global->player->attack = 1;
    if (KEY_TOUCH == sfKeyB)
        global->player->bomb = 1;
}

void ev_loop_running(sfRenderWindow *window, states *state, global_t *global)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (KEY_TOUCH == sfKeyEscape)
            sfRenderWindow_close(window);
        if (KEY_TOUCH == sfKeyP) {
            *state == running ? *state = paused :
            *state == paused ? *state = running : 0;
        }
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyC))
            change_map(global->map, MAP_PATHS[OUT_HOUSE]);
        if ((KEY_TOUCH == sfKeyLeft) || (KEY_TOUCH == sfKeyRight) ||
        (KEY_TOUCH == sfKeyUp) || (KEY_TOUCH == sfKeyDown))
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
