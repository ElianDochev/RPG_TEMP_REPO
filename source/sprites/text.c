/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** functions for creating text
*/

#include "sprites.h"

text_t *init_text(char const *str, sfFont *font, unsigned int font_size,
sfVector2f const *pos)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = font;
    text->text = sfText_create();
    sfText_setString(text->text, str);
    sfText_setFont(text->text, text->font);
    font_size == 0 ? 0 : sfText_setCharacterSize(text->text, font_size);
    pos == NULL ? 0 : sfText_setPosition(text->text, *pos);
    return text;
}

void destroy_text(text_t *text)
{
    sfText_destroy(text->text);
    text->font = NULL;
    xfree((void **) &text);
}
