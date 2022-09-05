/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** different loop menus
*/

#include "buttons.h"
#include "main.h"

void loop_menu(button_text_t *botton, void *element, sfEvent event,
sfRenderWindow *window)
{
    if (!is_mouse_on_btext(botton, window)) {
        change_bntxt_color(botton, idle_bn);
        return;
    }
    if (is_click_or_hover_bntxt(botton, event) == 1) {
        botton->ptr(element);
    }
}
