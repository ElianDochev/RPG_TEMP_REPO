/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_player
*/

#include "player.h"
#include "m_my.h"
#include "main.h"
#include "items.h"
#include <fcntl.h>
#include <unistd.h>

static sprite_t **init_player_sprites(player_t *player)
{
    sprite_t **sprites = malloc(sizeof(sprite_t *) * PLAYER_TEXTURE_NB);

    for (int i = 0; i < PLAYER_TEXTURE_NB; i++)
        sprites[i] = set_sprite(player->textures[i], NULL, NULL,
        get_sfvector2f(1.5, 1.5));
    return sprites;
}

static sfTexture **init_player_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * PLAYER_TEXTURE_NB);

    for (int i = 0; i < PLAYER_TEXTURE_NB; i++)
        textures[i] = sfTexture_createFromFile(PLAYER_PATHS_NAME[i],
        get_int_rect(PLAYER_RECT[i][0], PLAYER_RECT[i][1],
        PLAYER_RECT[i][2], PLAYER_RECT[i][3]));
    for (int i = 0; i < PLAYER_TEXTURE_NB; i++)
        if (textures[i] != NULL)
            sfTexture_setSmooth(textures[i], sfTrue);
    return textures;
}

static player_stats_t *set_up_stats(config_t *conf)
{
    player_stats_t *stats = malloc(sizeof(player_stats_t));

    stats->live = conf->confs[conf_lives];
    stats->attack_value = conf->confs[conf_attack];
    stats->defense = conf->confs[conf_defense];
    stats->inventory = NULL;
    return stats;
}

static sfMusic *init_music(config_t *conf)
{
    sfMusic *music = sfMusic_createFromFile(conf->paths[game_paused_music]);
    if (!music)
        return (NULL);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, (float) conf->confs[music_vol_cf]);
    return (music);
}

player_t *set_up_player(const char *path, config_t *conf)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return NULL;
    player->map =  my_str_to_word_array(get_map(path));
    player->textures = init_player_textures();
    player->sprites = init_player_sprites(player);
    player->direction = 0;
    player->attack = 0;
    player->move = 0;
    player->bomb = 0;
    player->nbr_map = 0;
    player->money = 0;
    player->ruby = 0;
    player->life = 10;
    player->stats = set_up_stats(conf);
    player->music = init_music(conf);
    return player;
}
