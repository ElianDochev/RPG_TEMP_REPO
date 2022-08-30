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
#######################BEGINING OF SPRITES SEGMENT###########################
#############################################################################*/

//object for sprites
typedef struct sprite
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rect;
} sprite_t;

////////////////////////////////////////////////////////////
/// \brief Creates a sprite object
///
/// \param texture    takes a pointer to a texture or NULL
/// \param path       if texture is NULL, takes the path to the texture
/// \param rect       pointer to an intrect or NULL
/// \param scale_vector     pointer to a vector or NULL
///(use maroan's func to create the vector)
///
/// \return  pointer to the sprite object
///
///////////////////////////////////////////////////////////
sprite_t *set_sprite(sfTexture *texture, char *path, sfIntRect *rect,
sfVector2f *scale_vector);
/*###########################################################################
#######################END OF SPRITES SEGEMENT###############################
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
