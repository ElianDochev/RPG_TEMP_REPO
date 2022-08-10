/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** buttons test .c
*/

// #include "utilities.h"
// #include "../../include/buttons.h"
// #include <stdio.h>

// int test(void)
// {
//     return 0;
// }

// int is_clicked(button_t *button, sfVector2f click_pos)
// {
//     button->print_rect.left = 0;
//     button->hitbox = sfSprite_getGlobalBounds(button->button_shape);
//     if (sfFloatRect_contains(&button->hitbox, click_pos.x, click_pos.y)) {
//         button->print_rect.left = 16;
//         return 1;
//     }
//     sfSprite_setTextureRect(button->button_shape, button->print_rect);
//     return 0;
// }

// void init_button(button_t *button, sfVector2f position)
// {
//     sfVector2f size = {10, 10};

//     button->print_rect.left = 0;
//     button->print_rect.top = 0;
//     button->print_rect.height = 16;
//     button->print_rect.width = 16;
//     button->button_shape = sfSprite_create();
//     sfSprite_setPosition(button->button_shape, position);
//     button->texture = sfTexture_createFromFile
//     ("source/tests/GOOMBA.png", NULL);
//     sfSprite_setTexture(button->button_shape, button->texture, sfFalse);
//     sfSprite_setTextureRect(button->button_shape, button->print_rect);
//     sfSprite_setScale(button->button_shape, size);
//     button->ptr = &test;
// }

// int main(void)
// {
//     sfVideoMode video_mode = {1920, 1080, 32};
//     sfRenderWindow *window =
//     sfRenderWindow_create(video_mode, "TEST", sfClose, NULL);
//     sfEvent *event;
//     button_t button;
//     sfVector2f size = {10, 10};
//     sfVector2f position = {10, 10};

//     init_button(&button, position);

//     while (sfRenderWindow_isOpen(window)) {
//         sfRenderWindow_display(window);
//         sfRenderWindow_clear(window, sfBlue);
//         sfRenderWindow_drawSprite(window, button.button_shape, NULL);
//         while (sfRenderWindow_pollEvent(window, event)) {
//             if (event->type == sfEvtClosed)
//                 sfRenderWindow_close(window);
//             if (event->type == sfEvtMouseButtonPressed &&
//             is_clicked(&button, con_vi_to_vf
//             (sfMouse_getPositionRenderWindow(window)))){
//                 button.ptr();
//                 sfRenderWindow_close(window);
//             }
//         }
//     }
// }