/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** cursor
*/

#include "main.h"
#include "stdio.h"

cursor_t *set_up_cursor(char *cursor_path)
{
    cursor_t *cursor = NULL;
    sfVector2f scale_vector = {1.2, 1.2};

    cursor = set_sprite(NULL, cursor_path, NULL, &scale_vector);
    return cursor;
}

void set_cursor_to_mouse(cursor_t *cursor, sfRenderWindow *window)
{
    sfVector2f mouse_pos =
    con_vi_to_vf(sfMouse_getPositionRenderWindow(window));

    sfSprite_setPosition(cursor->sprite, mouse_pos);
    sfRenderWindow_drawSprite(window, cursor->sprite, NULL);
}

void destroy_cursor(cursor_t *cursor)
{
    destroy_sprite((sprite_t *) cursor, DESTOY_TEXTURE);
}
