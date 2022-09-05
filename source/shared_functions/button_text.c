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

button_text_t *init_button_text(button_text_info_t *info, void(*ptr)(void *),
sfFont *font, char *msg)
{
    button_text_t *button = malloc(sizeof(button_text_t));

    button->location = info->location;
    button->text = init_text(msg, font, info->font_size, &(button->location));
    button->ptr = ptr;
    button->bn_color[idle_bn]  = *(sfColor *) info->bn_color[idle_bn];
    button->bn_color[on_click] = *(sfColor *) info->bn_color[on_click];
    button->bn_color[on_hover] = *(sfColor *) info->bn_color[on_hover];
    sfText_setFillColor(button->text->text, button->bn_color[idle_bn]);
    button->hitbox = sfText_getGlobalBounds(button->text->text);
    if (info->is_for_single_use == 1)
        xfree((void **) &info);
    return button;
}

void change_bntxt_color(button_text_t *button, button_state state)
{
    sfText_setFillColor(button->text->text, button->bn_color[state]);
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

void destroy_button_text(button_text_t *button, int mask)
{
    destroy_text(button->text, mask);

    xfree((void **) &button);
}
