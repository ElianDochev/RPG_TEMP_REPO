/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu of text bottons
*/

#include "buttons.h"
#include "main.h"

button_text_t **set_up_menu_bntext(sfFont *font, sfVector2f vect,
char **msg_arr, void (*ptr[])(void *))
{
    int len = get_len_two_d(msg_arr);
    button_text_t **menu = malloc(sizeof(button_text_t *) * (len + 1));

    for (int i = 0; i < len; ++i)
        menu[i] = init_button_text(vect, ptr[i], font, msg_arr[i]);
    menu[len] = NULL;
    return menu;
}

void draw_menu_bntext(button_text_t **menu , sfRenderWindow *window,
float offset_x, float offset_y)
{
    sfVector2f vect = sfText_getPosition(menu[0]->text->text);

    for (int i = 0; menu[i] ; ++i) {
        sfText_setPosition(menu[i]->text->text,
        create_fvector(vect.x + i * offset_x, vect.y + i * offset_y));
        sfRenderWindow_drawText(window, menu[i]->text->text, NULL);
    }
}

void destroy_menu_bntext(button_text_t **menu)
{
    for (int i = 0; menu[i]; ++i)
        destroy_button_text(menu[i]);
    xfree((void **) &menu);
}
