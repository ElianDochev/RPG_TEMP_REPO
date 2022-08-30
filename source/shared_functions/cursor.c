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
    textures_t_old *texture = init_texture(cursor_path, NULL);
    cursor_t *cursor = set_sprite(texture);

    sfSprite_setScale(cursor->sprite, create_fvector(1.2, 1.2));
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
    destroy_texture(cursor->texture);
    destroy_sprite(cursor);
}
