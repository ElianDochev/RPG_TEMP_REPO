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
}

static void continued(slider_info_text_t text_info,
slider_info_slide_t slide_info, slider_t *slider, sfVector2f location)
{
    sfVector2f slider_loc = {location.x + slide_info.offset.x,
    location.y + slide_info.offset.y};

    slide_info.colors[1] != NULL ? sfRectangleShape_setOutlineColor
    (slider->slider, *(sfColor *) slide_info.colors[3]) : 0;
    slide_info.o_thick.x != 0 ? sfRectangleShape_setOutlineThickness
    (slider->slider, slide_info.o_thick.x) : 0;
    slider->knob = sfCircleShape_create();
    sfCircleShape_setRadius(slider->knob, slide_info.size.y / 2);
    sfCircleShape_setPosition(slider->knob, slider_loc);
    sfCircleShape_setFillColor(slider->knob, *(sfColor *) slide_info.colors[2]);
    slide_info.colors[4] != NULL ? sfCircleShape_setOutlineColor(slider->knob,
    *(sfColor *) slide_info.colors[4]) : 0;
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
    continued(text_info, slide_info, slider, location);
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

// int main(void)
// {
//     sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "test", sfDefaultStyle, NULL);
//     sfRectangleShape *rect = sfRectangleShape_create();
//     sfCircleShape *circle = sfCircleShape_create();
//     sfFloatRect vect;
//     int thickness = 10;

//     sfRectangleShape_setSize(rect, (sfVector2f){150, thickness});
//     sfRectangleShape_setPosition(rect, (sfVector2f){100, 100});
//     sfRectangleShape_setFillColor(rect, sfRed);
//     sfCircleShape_setRadius(circle,(float) thickness / 2);
//     sfCircleShape_setPosition(circle, (sfVector2f){100, 100});
//     vect = sfRectangleShape_getGlobalBounds(rect);
//     vect = (sfFloatRect){vect.left, vect.top, vect.width, vect.height / 2};
//     while (sfRenderWindow_isOpen(window)) {
//         sfEvent event;
//         while (sfRenderWindow_pollEvent(window, &event)) {
//             if (event.type == sfEvtClosed)
//                 sfRenderWindow_close(window);
//         }
//         sfRenderWindow_clear(window, sfBlack);
//         sfRenderWindow_drawRectangleShape(window, rect, NULL);
//         if (sfFloatRect_contains(&vect,
//             sfMouse_getPositionRenderWindow(window).x,
//             sfMouse_getPositionRenderWindow(window).y)) {
//                 fflush(stdout);
//                 if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
//                     sfCircleShape_setPosition(circle,
//                     (sfVector2f){
//                         sfMouse_getPositionRenderWindow(window).x,
//                         sfCircleShape_getPosition(circle).y});
//                     float percent = (sfMouse_getPositionRenderWindow(window).x - vect.left) / vect.width;
//                     printf("percents %f , rounded number %d\n", percent,(int) round((double) thickness * percent));
                    
//                 }
//             }
//         sfRenderWindow_drawCircleShape(window, circle, NULL);
//         sfRenderWindow_display(window);
//     }
//     return 0;
// }