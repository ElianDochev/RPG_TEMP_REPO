/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** function that display if parameter is negative, positive or null
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    my_putchar('\n');
    return 0;
}
