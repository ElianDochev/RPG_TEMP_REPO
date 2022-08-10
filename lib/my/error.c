/*
** EPITECH PROJECT, 2022
** Utility
** File description:
** display a msg to stderr
*/

#include <unistd.h>
#include "utilities.h"

void error (char *str)
{
    write(2, str, my_strlen(str));
}
