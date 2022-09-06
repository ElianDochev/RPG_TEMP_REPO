/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** button functions
*/

#include "start_menu.h"

static void exit_help(void *running)
{
    *(int *) running = 0;
}

static void local_event_loop(sfRenderWindow *window, int *running,
button_text_t **menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        for (int i = 0; menu[i]; ++i) {
            loop_menu(menu[i], running, event, window);
        }
    }
}

static void second_part(start_menu_elements_t *element,
button_text_t **menu, text_t *text, time_mana_t *clock)
{
    int running = 1;
    sfRenderWindow *window = element->window;
    config_t *config = element->conf;
    sfVector2f vect = con_vu_to_vf(get_center_xy_pcn(window, -0.43f, -0.4f));

    sfText_setPosition(text->text, vect);
    while (sfRenderWindow_isOpen(window) && running) {
        local_event_loop(window, &running, menu);
        clock->time = sfClock_getElapsedTime(clock->clock);
        clock->millisec = clock->time.microseconds;
        if (clock->millisec > config->confs[refresh_rate_ov_st]) {
            sfRenderWindow_drawSprite(window, element->background->sprite, NULL);
            sfRenderWindow_drawText(window, text->text, NULL);
            draw_menu_bntext(menu, window);
            set_cursor_to_mouse(element->cursor, window);
            sfRenderWindow_display(window);
            sfClock_restart(clock->clock);
        }
    }
    sfClock_destroy(clock->clock);
}

void display_help(void *element)
{
    start_menu_elements_t *ele = (start_menu_elements_t *)  element;
    char *buff = fopen_file("how_to_play.txt", "help file not found");
    void (*fptr[1])(void *) = {exit_help};
    void *color[3] = {&sfWhite, &sfBlack, &sfYellow};
    button_text_t **menu =
    set_up_menu_bntext(ele->main_font,init_button_text_info(con_vu_to_vf
    (get_center_xy_pcn(ele->window, -0.05f, 0.1f)), color,
    (sfVector2f) {0, 0}, 40), (char *[]) {"Go back", NULL}, fptr);
    text_t *text = NULL;
    time_mana_t *clock = get_clock();

    if (buff == NULL)
        return;
    text = init_text(buff,sfFont_createFromFile
    ("resources/fonts/orange_juice_2.0.ttf"), FONT_SIZE_HELP, NULL);
    sfText_setFillColor(text->text, FONT_COLOR_HELP);
    second_part(ele, menu, text, clock);
    destroy_menu_bntext(menu, 0);
    destroy_text(text, DESTOY_FONT);
    free(clock);
}