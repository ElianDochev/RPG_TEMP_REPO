/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Main game loop
*/

#include "main.h"
#include "sprites.h"
#include "player.h"

global_t *set_up_global(int lives)
{
    global_t *global = malloc(sizeof(global_t));

    global->lives = lives;
    global->map = create_map(MAP_PATHS[SANCTUARY_ENTRY]);
    global->player = set_up_player(PLAYER_MAP_PATHS[OUT_HOUSE]);
    return global;
}

void reset_global(global_t *global, int lives)
{
    global->lives = lives;
}

void check_game_state(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    void (*control_blocks[]) (sfRenderWindow *, states *, global_t *,
    config_t *) = {&start_menu, &game_paused, &game_running, &game_over};

    if (*game_state == gm_quit) {
        sfRenderWindow_close(window);
        return;
    }
    control_blocks[*game_state](window, game_state, global, conf);
}

void destroy_global(global_t *global)
{
    destroy_map(global->map);
    free(global);
}

void main_game_loop(int *error)
{
    config_t *config = set_up_config();
    sfRenderWindow *window = config != NULL ? create_window(config) : NULL;
    states game_state = gm_over;
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
    destroy_global(global);
    sfRenderWindow_destroy(window);
}
