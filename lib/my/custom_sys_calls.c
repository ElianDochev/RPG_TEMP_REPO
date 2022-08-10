/*
** EPITECH PROJECT, 2022
** Utility
** File description:
** contains alt var of free
*/

#include "utilities.h"
#include <stdlib.h>

void xfree(void **ptr)
{
        free(*ptr);
        *ptr = NULL;
}
