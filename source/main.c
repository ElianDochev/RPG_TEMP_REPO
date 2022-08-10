/*
** EPITECH PROJECT, 2022
** project name
** File description:
** main
*/

#include "main.h"
#include <fcntl.h>
#include <stdlib.h>

static void print_help(void)
{
    int fd = open("usage.txt", O_RDONLY);
    int buff_size = 32;
    char *buff = malloc(buff_size);
    int len = 1;

    while (len > 0 && buff != NULL) {
        len = read(fd, buff, buff_size - 1);
        write(1, buff, len);
    }
    xfree((void **) &buff);
    close(fd);
}

static void print_bad_args(int ac)
{
    ac += '0' - 1;
    write(2, "./my_rpg: bad arguments:", 29);
    write(2, &ac, 1);
    write(2, "given but 0 is required\nretry with -h\n", 38);
}

int main (int ac, char **av)
{
    int error = 0;

    if (ac != 1) {
        if (str_cmp(av[1], "-h") == 0) {
            print_help();
            return 0;
        }
        print_bad_args(ac);
        return EXIT_ERR_EPI;
    }
    main_game_loop(&error);
    return error == 0 ? 0 : EXIT_ERR_EPI;
}
