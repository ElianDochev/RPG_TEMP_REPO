/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** print character
*/

#include <unistd.h>

void my_putchar(unsigned char c)
{
    write(1, &c, 1);
}
