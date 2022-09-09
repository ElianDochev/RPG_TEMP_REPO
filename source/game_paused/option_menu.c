/*
** EPITECH PROJECT, 2022
** my
** File description:
** option menu for game paused
*/

#include "game_paused.h"

static void local_event_loop(sfRenderWindow *window, int *running)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyP))
            *running = 0;
    }
}

static void second_part(game_paused_elements_t *element,
button_text_t **button, slider_t **slider, time_mana_t *clock)
{
    int running = 1;
    config_t *config = element->conf;
    sfRenderWindow *window = element->window;

    while (sfRenderWindow_isOpen(window) && running) {
        local_event_loop(window, &running);
        clock->time = sfClock_getElapsedTime(clock->clock);
        clock->millisec = clock->time.microseconds;
        if (clock->millisec > config->confs[refresh_rate_ov_st]) {
            draw_map(window, element->global->map);
            draw_player(window, element->global->player);
            draw_ennemi(window, element->global);
            sfRenderWindow_drawRectangleShape(window,
            element->square_container, NULL);
            draw_slider(window, slider[0], (void *) element);
            draw_slider(window, slider[1], (void *) element);
            draw_menu_bntext(button, window, &running, NULL);
            set_cursor_to_mouse(element->cursor, window);
            sfRenderWindow_display(window);
            sfClock_restart(clock->clock);
        }
    }
}

static slider_t **set_options(sfRenderWindow *window,
game_paused_elements_t *element)
{
    slider_t **slider_arr = malloc(sizeof(slider_t *) * 2);
    slider_info_text_t text_info = set_up_slider_text(sfWhite, 30,
    element->main_font, "Music_Volume");
    slider_info_slide_t slide_info = set_up_slider_slide(option_colors,
    (sfVector2f){300, 10}, (sfVector2f){80, 16}, option_thinkness);

    slider_arr[0] = init_slider(text_info, slide_info , &change_volume_p,
    con_vu_to_vf(get_center_xy_pcn(window, -0.1, -0.1)));
    text_info.msg = "Sound_Volume";
    slider_arr[1] = init_slider(text_info, slide_info , &change_sound_p,
    con_vu_to_vf(get_center_xy_pcn(window, -0.1, 0.0)));
    return (slider_arr);
}

void open_options(void *arg, int index)
{
    game_paused_elements_t *element = (game_paused_elements_t *) arg;
    sfRenderWindow *window = element->window;
    void *btn_color[]= {&sfWhite, &sfBlack, &sfRed};
    slider_t **slider = set_options(window, element);
    button_text_t *button = init_button_text(init_button_text_info(
    con_vu_to_vf(get_center_xy_pcn(window, 0, 0.15)), btn_color,
    (sfVector2f) {0, 0}, 30), &exit_option, element->main_font, "Go back");
    int running = 1;
    time_mana_t *clock = get_clock();

    second_part(element, (button_text_t *[]) {button, NULL}, slider, clock);
    destroy_button_text(button, 0);
    sfClock_destroy(clock->clock);
    free(clock);
    destroy_slider(slider[0], 0);
    destroy_slider(slider[1], 0);
}