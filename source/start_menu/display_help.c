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

    while (sfRenderWindow_isOpen(window) && running) {
        local_event_loop(window, &running, menu);
        sfRenderWindow_drawSprite(window, element->background->sprite, NULL);
        sfRenderWindow_drawText(window, text->text, NULL);
        draw_menu_bntext(menu, window);
        set_cursor_to_mouse(element->cursor, window);
        sfRenderWindow_display(window);
    }
}

void display_help(void *element)
{
    start_menu_elements_t *ele = (start_menu_elements_t *)  element;
    char *buff = fopen_file("how_to_play.txt", "help file not found");
    void (*fptr[1])(void *) = {exit_help};
    void *color[3] = {&sfWhite, &sfBlack, &sfYellow};
    button_text_t **menu =
    set_up_menu_bntext(sfFont_createFromFile(ele->conf->paths[gm_over_font]),
    init_button_text_info(con_vu_to_vf(get_center_xy_pcn(ele->window
    , 0.f, 0.5f)), color, (sfVector2f) {0, 0}, 40),
    (char *[]) {"Go back", NULL}, fptr);
    text_t *text = NULL;
    time_mana_t *clock = get_clock();

    if (buff == NULL)
        return;
    text = init_text(buff, ele->main_font, FONT_SIZE_HELP, NULL);
    sfText_setFillColor(text->text, FONT_COLOR_HELP);
    second_part(ele, menu, text, clock);
    destroy_menu_bntext(menu, DESTOY_FONT);
    destroy_text(text, 0);
}