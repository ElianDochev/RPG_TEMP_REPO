/*
** EPITECH PROJECT, 2022
** my_compute_power_it.c
** File description:
** power it
*/

int my_compute_power_it(int nb, int p)
{
    int k = 1;
    if (p == 0)
        return (1);
    for (int i = 1; p; i++) {
        k = k * nb;
        p -= 1;
    }
    return k;
}
