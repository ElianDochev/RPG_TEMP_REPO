/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** display the number given as parameter
*/

void my_putchar(char c);

void my_put_nbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n > 9)
        my_put_nbr(n / 10);
    my_putchar((n % 10) + '0');
}
