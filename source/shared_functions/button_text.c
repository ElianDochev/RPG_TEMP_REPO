/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** text button
*/

#include "utilities.h"
#include "buttons.h"
#include <stdio.h>


int is_mouse_on_btext(button_text_t *button, sfRenderWindow *window)
{
    sfVector2f click_pos =
    con_vi_to_vf(sfMouse_getPositionRenderWindow(window));

    button->hitbox = sfText_getGlobalBounds(button->text->text);
    if (sfFloatRect_contains(&button->hitbox, click_pos.x, click_pos.y))
        return 1;
    return 0;
}

button_text_t *init_button_text(sfVector2f position, void(*ptr)(void *),
sfFont *font, char *msg)
{
    button_text_t *button = malloc(sizeof(button_text_t));

    button->location = position;
    button->text = init_text(msg, font, START_MENU_SIZE, &position);
    button->ptr = ptr;
    button->bn_color[idle_bn]  = *(sfColor *) bn_states_color[idle_bn];
    button->bn_color[on_click] = *(sfColor *) bn_states_color[on_click];
    button->bn_color[on_hover] = *(sfColor *) bn_states_color[on_hover];
    button->hitbox = sfText_getGlobalBounds(button->text->text);
    sfText_setColor(button->text->text, button->bn_color[idle_bn]);
    return button;
}

void change_bntxt_color(button_text_t *button, button_state state)
{
    sfText_setColor(button->text->text, button->bn_color[state]);
}

int is_click_or_hover_bntxt(button_text_t *button, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        change_bntxt_color(button, on_click);
        return 1;
    } else {
        change_bntxt_color(button, on_hover);
        return 2;
    }
}

void destroy_button_text(button_text_t *button)
{
    destroy_text(button->text);

    xfree((void **) &button);
}
