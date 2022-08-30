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
