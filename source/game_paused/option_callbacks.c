/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** functions executed when the user moves the sliders for start menu
*/

#include "game_paused.h"

void change_volume_p(void *arg, float percent)
{
    game_paused_elements_t *element = (game_paused_elements_t *) arg;
    unsigned int volume = (unsigned int) (percent * 100);

    volume = (unsigned int)
    round((float) percent * element->conf->confs[music_vol_cf]);
    sfMusic_setVolume(element->music, volume);
}

void change_sound_p(void *arg, float percent)
{
    game_paused_elements_t *element = (game_paused_elements_t *) arg;
    unsigned int volume = (unsigned int) (percent * 100);

    volume = (unsigned int)
    round((float) percent * element->conf->confs[sound_vol_cf]);
    element->vect.x = volume;
}