/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_maps
*/

#include "map.h"
#include "m_my.h"
#include <fcntl.h>
#include <unistd.h>

char *get_map(char *path)
{
    char *buffer = malloc(sizeof(char) * (MAX_X + 1) * MAX_Y);
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

sprite_t *choose_sprite(int y, int x, map_t *map)
{
    if (map->map[y][x] == GRASS)
        return set_sprite(map->textures[GRASS_TEXT], NULL, NULL, NULL);
    return NULL;
}

sprite_t ***create_array_of_sprites(map_t *map)
{
    sprite_t ***sprites = malloc(sizeof(sprite_t **) * MAX_Y);

    for (int y = 0; y < MAX_Y; y++) {
        sprites[y] = malloc(sizeof(sprite_t *) * MAX_X);
        for (int x = 0; x < MAX_X; x++)
            sprites[y][x] = choose_sprite(y, x, map);
    }
    return sprites;
}

sfTexture **init_map_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * TEXTURES_NB);

    textures[GRASS_TEXT] = sfTexture_createFromFile("tile_sets/grass_tile.png",
    get_int_rect(0, 16, 16, 0));
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
    return map;
}
