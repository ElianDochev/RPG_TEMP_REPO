/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** option functin main button
*/

#include "start_menu.h"
#include "buttons.h"
#include <math.h>

void test(void *arg, float percent)
{
    start_menu_elements_t *element = (start_menu_elements_t *) arg;
    unsigned int volume = (unsigned int) (percent * 100);

    volume = (unsigned int)
    round((float) percent * element->conf->confs[music_vol_cf]);
    sfMusic_setVolume(element->music, volume);
}

static void local_event_loop(sfRenderWindow *window, int *running,
button_text_t *button)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        loop_menu(button, running, event, window);
    }
}

void option(void *elements)
{
    start_menu_elements_t *element = (start_menu_elements_t *) elements;
    sfRenderWindow *window = element->window;
    config_t *config = element->conf;
    void *colors[] = {&sfWhite, &sfBlack, NULL, NULL};
    void *btn_color[]= {&sfWhite, &sfBlack, &sfBlue};
    slider_t *slider = init_slider(set_up_slider_text(sfWhite, 30,
    element->main_font, "Music_Volume"), set_up_slider_slide(colors,
    (sfVector2f){300, 10}, (sfVector2f){100, 16}, (sfVector2f){0, 0}),
    &test, con_vu_to_vf(get_center_xy_pcn(window, -0.1, 0)));
    button_text_t *button = init_button_text(init_button_text_info(
    con_vu_to_vf(get_center_xy_pcn(window, -0.1, 0.2)), btn_color,
    (sfVector2f) {0, 0}, 30), &exit_option, element->main_font, "Go back");
    int running = 1;
    time_mana_t *clock = get_clock();

    while (sfRenderWindow_isOpen(window) && running) {
        local_event_loop(window, &running, button);
        clock->time = sfClock_getElapsedTime(clock->clock);
        clock->millisec = clock->time.microseconds;
        if (clock->millisec > config->confs[refresh_rate_ov_st]) {
            sfRenderWindow_drawSprite(window, element->background->sprite, NULL);
            draw_slider(window, slider, elements);
            sfRenderWindow_drawText(window, button->text->text, NULL);
            set_cursor_to_mouse(element->cursor, window);
            sfRenderWindow_display(window);
            sfClock_restart(clock->clock);
        }
    }
    sfClock_destroy(clock->clock);
    destroy_slider(slider, 0);
}