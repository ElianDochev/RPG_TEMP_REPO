/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** windows init and stuff
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "main.h"

sfRenderWindow *create_window(config_t *config)
{
    sfVideoMode mode = {config->confs[width_cf], config->confs[height_cf],
    config->confs[bpp_cf]};
    sfRenderWindow *window;

    window = config->confs[fullscreen_cf] == sfTrue ?
    sfRenderWindow_create(mode, "my_rpg",
    sfClose | sfTitlebar | sfFullscreen, NULL) :
    sfRenderWindow_create(mode, "my_rpg",
    sfClose | sfTitlebar, NULL);
    if (!window ) {
        error("render windows failed\n");
        return NULL;
    }
    sfRenderWindow_setFramerateLimit(window, config->confs[frame_rate_cf]);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return window;
}
