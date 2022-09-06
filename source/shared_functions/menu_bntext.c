/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu of text bottons
*/

#include "buttons.h"
#include "main.h"

button_text_info_t *init_button_text_info(sfVector2f location,
void const  **color, sfVector2f offset, int font_size)
{
    button_text_info_t *info = malloc(sizeof(button_text_info_t));

    info->location = location;
    info->offset = offset;
    for (int i = 0; i < on_hover + 1; i++)
        info->bn_color[i] = color[i];
    info->font_size = font_size;
    info->is_for_single_use = 1;
    return (info);
}

button_text_t **set_up_menu_bntext(sfFont *font, button_text_info_t *info,
char **msg_arr, void (*ptr[])(void *))
{
    int len = get_len_two_d(msg_arr);
    button_text_t **menu = malloc(sizeof(button_text_t *) * (len + 1));

    info->is_for_single_use = 0;
    for (int i = 0; i < len; ++i) {
        menu[i] = init_button_text(info, ptr[i], font, msg_arr[i]);
        info->location.y += info->offset.y;
        info->location.x += info->offset.x;
    }
    menu[len] = NULL;
    xfree((void **) &info);
    return menu;
}

void draw_menu_bntext(button_text_t **menu , sfRenderWindow *window)
{
    sfVector2f vect = sfText_getPosition(menu[0]->text->text);

    for (int i = 0; menu[i] ; ++i) {
        sfRenderWindow_drawText(window, menu[i]->text->text, NULL);
    }
}

void destroy_menu_bntext(button_text_t **menu, int mask)
{
    for (int i = 0; menu[i]; ++i) {
        if (CHK_FLAG(mask, DESTOY_FONT) == 1) {
            sfFont_destroy(menu[i]->text->font);
            UNSET_FLAG(mask, DESTOY_FONT);
        }
        destroy_button_text(menu[i], 0);
    }
    xfree((void **) &menu);
}
