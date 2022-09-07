/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** Slider object
*/

#include "buttons.h"
#include <stdio.h>
#include <math.h>

slider_info_text_t set_up_slider_text(sfColor color, int font_size,
sfFont *font, char *msg)
{
    slider_info_text_t info;

    info.txt_color = color;
    info.font_size = font_size;
    info.font = font;
    info.msg = msg;
    return (info);
}

slider_info_slide_t set_up_slider_slide(void **colors, sfVector2f offset,
sfVector2f size, sfVector2f o_thickness)

{
    slider_info_slide_t info;

    info.colors = colors;
    info.offset = offset;
    info.size = size;
    info.o_thick = o_thickness;
    return (info);
}

static void continued(slider_info_text_t text_info,
slider_info_slide_t slide_info, slider_t *slider, sfVector2f slider_loc)
{
    slide_info.colors[2] != NULL ? sfRectangleShape_setOutlineColor
    (slider->slider, *(sfColor *) slide_info.colors[2]) : 0;
    slide_info.o_thick.x != 0 ? sfRectangleShape_setOutlineThickness
    (slider->slider, slide_info.o_thick.x) : 0;
    slider->knob = sfCircleShape_create();
    sfCircleShape_setRadius(slider->knob, slide_info.size.y / 2);
    sfCircleShape_setPosition(slider->knob, (sfVector2f) {slider_loc.x +
    slide_info.size.x, slider_loc.y});
    sfCircleShape_setFillColor(slider->knob, *(sfColor *) slide_info.colors[1]);
    slide_info.colors[3] != NULL ? sfCircleShape_setOutlineColor(slider->knob,
    *(sfColor *) slide_info.colors[3]) : 0;
    slide_info.o_thick.y != 0 ? sfCircleShape_setOutlineThickness(
    slider->knob, slide_info.o_thick.y) : 0;
    slider->hitbox = sfRectangleShape_getGlobalBounds(slider->slider);
    slider->hitbox.height = slider->hitbox.height / 2;
}

slider_t *init_slider(slider_info_text_t text_info,
slider_info_slide_t slide_info, void (*func_ptr)(void *, float),
sfVector2f location)
{
    slider_t *slider = malloc(sizeof(slider_t));
    sfVector2f slider_loc = {location.x + slide_info.offset.x,
    location.y + slide_info.offset.y};

    slider->text = init_text(text_info.msg, text_info.font,
    text_info.font_size, &(location));
    slider->slider = sfRectangleShape_create();
    sfText_setColor(slider->text->text, text_info.txt_color);
    sfRectangleShape_setSize(slider->slider, slide_info.size);
    sfRectangleShape_setPosition(slider->slider, slider_loc);
    sfRectangleShape_setFillColor(slider->slider,
    *(sfColor *) slide_info.colors[0]);
    continued(text_info, slide_info, slider, slider_loc);
    slider->func_ptr = func_ptr;
    return (slider);
}

void destroy_slider(slider_t *slider, int mask)
{
    if (CHK_FLAG(mask, DESTOY_FONT))
        destroy_text(slider->text, DESTOY_FONT);
    else
        destroy_text(slider->text, 0);
    sfRectangleShape_destroy(slider->slider);
    sfCircleShape_destroy(slider->knob);
    xfree((void **) &slider);
}
