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

static char *get_map(char *path)
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

static sprite_t *choose_sprite(int y, int x, map_t *map)
{
    if (map->map[y][x] == GRASS)
        return set_sprite(map->textures[GRASS_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    if (map->map[y][x] == WALL_LEFT)
        return set_sprite(map->textures[WALL_LEFT_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    if (map->map[y][x] == WALL_RIGHT)
        return set_sprite(map->textures[WALL_RIGHT_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    if (map->map[y][x] == WALL_UP)
        return set_sprite(map->textures[WALL_UP_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    if (map->map[y][x] == WALL_NO)
        return set_sprite(map->textures[WALL_NO_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    if (map->map[y][x] == WALL_DOWN)
        return set_sprite(map->textures[WALL_DOWN_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
   if (map->map[y][x] == WALL_NE)
        return set_sprite(map->textures[WALL_NE_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
   if (map->map[y][x] == WALL_SO)
        return set_sprite(map->textures[WALL_SO_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
   if (map->map[y][x] == WALL_SE)
        return set_sprite(map->textures[WALL_SE_TEXT], NULL, NULL,
        get_sfvector2f(4, 4));
    return NULL;
}

static sprite_t ***create_array_of_sprites(map_t *map)
{
    sprite_t ***sprites = malloc(sizeof(sprite_t **) * MAX_Y);

    for (int y = 0; y < MAX_Y; y++) {
        sprites[y] = malloc(sizeof(sprite_t *) * MAX_X);
        for (int x = 0; x < MAX_X; x++)
            sprites[y][x] = choose_sprite(y, x, map);
    }
    return sprites;
}

static sfTexture **init_map_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * TEXTURES_NB);

    textures[GRASS_TEXT] = sfTexture_createFromFile("tile_sets/grass_tile.png",
    get_int_rect(0, 16, 16, 0));
    textures[WALL_LEFT_TEXT] = sfTexture_createFromFile("tile_sets/wall_tiles.png",
    get_int_rect(16, 16, 16, 0));
    textures[WALL_DOWN_TEXT] = sfTexture_createFromFile("tile_sets/wall_tiles.png",
    get_int_rect(32, 16, 16, 16));
    textures[WALL_RIGHT_TEXT] = sfTexture_createFromFile("tile_sets/wall_tiles.png",
    get_int_rect(16, 16, 16, 32));
    textures[WALL_UP_TEXT] = sfTexture_createFromFile("tile_sets/wall_tiles.png",
    get_int_rect(0, 16, 16, 16));
    textures[WALL_NO_TEXT] = sfTexture_createFromFile("tile_sets/wall_tiles.png",
    get_int_rect(0, 16, 16, 0));
    textures[WALL_NE_TEXT] = sfTexture_createFromFile("tile_sets/wall_tiles.png",
    get_int_rect(0, 16, 16, 32));
    textures[WALL_SE_TEXT] = sfTexture_createFromFile("tile_sets/wall_tiles.png",
    get_int_rect(32, 16, 16, 32));
    textures[WALL_SO_TEXT] = sfTexture_createFromFile("tile_sets/wall_tiles.png",
    get_int_rect(32, 16, 16, 0));
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
    return map;
}
