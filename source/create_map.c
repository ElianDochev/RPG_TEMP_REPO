/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_maps
*/

#include "map.h"
#include "m_my.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char *get_map(char *path)
{
    char *buffer = malloc(sizeof(char) * (MAX_X + 1) * MAX_Y + 1);
    int fd = 0;

    if (buffer == NULL)
        return NULL;
    if ((fd = open(path, O_RDONLY)) == -1)
        return NULL;
    if (read(fd, buffer, (MAX_X + 1) * MAX_Y) == -1)
        return NULL;
    buffer[(MAX_X + 1) * MAX_Y] = '\0';
    close(fd);
    return buffer;
}

static sprite_t **create_array_of_sprites(map_t *map)
{
    sprite_t **sprites = malloc(sizeof(sprite_t *) * TEXTURES_NB);

    for (int i = 0; i < TEXTURES_NB; i++)
        sprites[i] = set_sprite(map->textures[i], NULL, NULL,
        get_sfvector2f(4, 4));
    return sprites;
}

static sfTexture **init_map_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * TEXTURES_NB);

    for (int i = 0; i < TEXTURES_NB; i++)
        textures[i] = sfTexture_createFromFile(TILES_PATHS[i],
        get_int_rect(RECT[i][0], RECT[i][1], RECT[i][2], RECT[i][3]));
    for (int i = 0; i < TEXTURES_NB; i++)
        if (textures[i] != NULL)
            sfTexture_setSmooth(textures[i], sfTrue);
    return textures;
}

map_t *create_map(char *path)
{
    map_t *map = malloc(sizeof(map_t));
    char *buffer = get_map(path);

    if (map == NULL)
        return NULL;
    if (buffer == NULL)
        return NULL;
    map->textures = init_map_textures();
    map->map = my_str_to_word_array(buffer);
    map->sprites = create_array_of_sprites(map);
    free(buffer);
    return map;
}

void change_map(map_t *map, char *path)
{
    char *buffer = get_map(path);

    if (buffer == NULL) {
        write(STDERR_FILENO, "Invalid path or map can't change map\n", 38);
        return;
    }
    free_board(map->map);
    map->map = my_str_to_word_array(buffer);
    return map;
}
