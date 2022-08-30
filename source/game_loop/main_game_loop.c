/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Main game loop
*/

#include "main.h"
#include "sprites.h"

global_t *set_up_global(int lives)
{
    global_t *global = malloc (sizeof(global_t));

    global->score = 0;
    global->win = sfFalse;
    global->lives = lives;
    global->map = create_map("maps/out_house.map");
    return global;
}

void reset_global(global_t *global, int lives)
{
    global->score = 0;
    global->win = sfFalse;
    global->lives = lives;
}

void check_game_state(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    if (*game_state == gm_quit) {
        sfRenderWindow_close(window);
        return;
    }
    void (*control_blocks[]) (sfRenderWindow *, states *, global_t *,
    config_t *) = {&start_menu, &game_paused, &game_running, &game_over};
    control_blocks[*game_state](window, game_state, global, conf);
}

void main_game_loop(int *error)
{
    config_t *config = set_up_config();
    sfRenderWindow *window = config != NULL ? create_window(config) : NULL;
    states game_state = not_started;
    sfClock *clock = sfClock_create();
    global_t *global = set_up_global(config->confs[conf_lives]);

    if (window == NULL) {
        *error = EXIT_ERR_EPI;
        return;
    }
    while (sfRenderWindow_isOpen(window)) {
        event_loop(window, &game_state);
        check_game_state(window, &game_state, global, config);
    }
    xfree((void **) &config);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
}
