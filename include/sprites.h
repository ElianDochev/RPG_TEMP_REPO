/*
** EPITECH PROJECT, 2022
** HEADER FILE
** File description:
** sprites header structs and functions
*/

#ifndef SPRITES_H
    #define SPRITES_H

    #include "utilities.h"
    #include <stdlib.h>

/*###########################################################################
######################BEGINING OF TEXTURE OBJECT SEGMENT#####################
#############################################################################*/
//big side note use sprite_path and sprite_dims are interchangeable be careful
typedef struct {
    sfVector2u const *sp_sheet_entities;
    sfTexture *texture;
} textures_t;
//sets a texture pass a path and the spritesheet dims
textures_t *init_texture(char const *path, sfVector2u const *dims);
//sets an array of textures pass an array of paths and corocponding dims
//starts from 0
textures_t **make_text_array(int start, int finish, char const **paths,
sfVector2u const *dim);
//destroyts a texture
void destroy_texture(textures_t *texture);
//destroyts a texture array
void destroy_text_array(textures_t **array);
/*###########################################################################
#######################END OF TEXTURE SEGMENT################################
-----------------------------------------------------------------------------*/



/*###########################################################################
######################BEGINNING OF SPRITE OBJECT SEGMENT######################
#############################################################################*/
typedef struct {
    sfSprite   *sprite;
    textures_t *texture;
} sprite_t;
//set the correct sprite position for the sprite sheet
void set_position(sprite_t *sprite, int row, int colon);
//inits a sprite and sets texture
sprite_t *set_sprite(textures_t *texture);
//sets the array of sprites from one texture
sprite_t **set_sprites_same(int number_of_sprites, textures_t *texture);
//sets the array of sprites from multiple textures
sprite_t **set_sprites_dif(int number_of_sprites, textures_t **texture);
//destroys an sprite_t instance
void destroy_sprite(sprite_t *sprite);
//destroys an array of sprite_t instances
void destroy_array_sprites(sprite_t **sprites);
/*###########################################################################
#######################END OF SPRITE SEGMENT#################################
-----------------------------------------------------------------------------*/



/*###########################################################################
#######################BEGINING OF TEXT######################################
#############################################################################*/
//struct for text object
typedef struct {
    sfFont *font;
    sfText *text;
} text_t;
//set a postion for the text
void set_text_pos(text_t *text, sfVector2f pos);
//inits a text (pass a 0 to font for default font and NULL for default pos)
text_t *init_text(char const *str, sfFont *font, unsigned int font_size,
sfVector2f const *pos);
//destroys a text object
void destroy_text(text_t *text);
/*###########################################################################
#########################END OF TEXT#########################################
-----------------------------------------------------------------------------*/
#endif
