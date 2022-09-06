/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** animates the slider object
*/

#include "buttons.h"


void draw_slider(sfRenderWindow *window, slider_t *slider, void *arg)
{
    float percent = 0;

    if (sfFloatRect_contains(&slider->hitbox,
    sfMouse_getPositionRenderWindow(window).x,
    sfMouse_getPositionRenderWindow(window).y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfCircleShape_setPosition(slider->knob,
            (sfVector2f){
            sfMouse_getPositionRenderWindow(window).x,
            sfCircleShape_getPosition(slider->knob).y});
            percent = (sfMouse_getPositionRenderWindow(window).x -
            slider->hitbox.left) / slider->hitbox.width;
            slider->func_ptr(arg, percent);
        }
    }
    sfRenderWindow_drawRectangleShape(window, slider->slider, NULL);
    sfRenderWindow_drawCircleShape(window, slider->knob, NULL);
    sfRenderWindow_drawText(window, slider->text->text, NULL);
}
