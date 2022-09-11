/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** functions executed when the user moves the sliders for start menu
*/

#include "start_menu.h"
#include <math.h>

void change_volume(void *arg, float percent)
{
    start_menu_elements_t *element = (start_menu_elements_t *) arg;
    unsigned int volume = (unsigned int) (percent * 100);

    volume = (unsigned int)
    round((float) percent * element->conf->confs[music_vol_cf]);
    sfMusic_setVolume(element->music, volume);
}

void change_sound(void *arg, float percent)
{
    start_menu_elements_t *element = (start_menu_elements_t *) arg;
    unsigned int volume = (unsigned int) (percent * 100);

    volume = (unsigned int)
    round((float) percent * element->conf->confs[sound_vol_cf]);
    element->vect.x = volume;
}
