/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** convets an int to str
*/

#include "utilities.h"
#include <stdlib.h>

static int get_number_digits(int *n, sfInt32 *scr, int *m)
{
    int count = 0;

    if (*scr < 0) {
        (*n) = (*n) * (-1);
        (*scr) = (*scr) * (-1);
        *m = 1;
    }
    while (*n != 0) {
        *n = *n / 10;
        ++count;
    }
    return count;
}

static char *check_minus_zero(char *dest, int i, int minus, sfInt32 num)
{
    if (num == 0) {
        xfree((void **) &dest);
        dest = malloc(2);
        dest[0] = '0';
        dest[1] = '\0';
        return dest;
    }
    dest[i - 1 + minus] = '\0';
    if (minus == 1)
        dest[0] = '-';
    return dest;
}

char *int_to_str(sfInt32 scr)
{
    sfInt32 n = scr;
    char tmp;
    char *dest;
    int i = 1;
    int minus = 0;
    int count = get_number_digits(&n, &scr, &minus);

    dest = malloc(count + 1 + minus);
    for (; i <= count; ++i) {
        n = scr;
        n = n / calc_pow(10, count - i);
        n = n % 10;
        tmp = n + 48;
        dest[i - 1 + minus] = tmp;
    }
    dest = check_minus_zero(dest, i, minus, scr);
    return dest;
}
