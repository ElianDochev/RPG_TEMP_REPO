/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to define bool functions
*/

#include "map.h"
#include "m_my.h"

bool is_in_special(int nb)
{
    for (int i = 0; i < SPECIALS__NB; i++)
        if (SPECIALS[i] == nb)
            return true;
    return false;
}