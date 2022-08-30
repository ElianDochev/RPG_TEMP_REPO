/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** function that swap the content of two integer
*/

void my_swap(int *first, int *second)
{
    int third = *first;

    *first = *second;
    *second = third;
}
