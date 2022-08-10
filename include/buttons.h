/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** button test .h
*/

#ifndef BUTTONS_H_
    #define BUTTONS_H_

    #include "sprites.h"

typedef enum{idle_bn, on_click, on_hover} button_state;
typedef struct button_s
{
    sfTexture *texture;
    sfSprite *button_shape;
    sfFloatRect hitbox;
    sfIntRect print_rect;
    void (*ptr)(void *value);
} button_t;



/*###########################################################################
######################BEGINING OF TEXT BOTTONS SEGMENT#######################
#############################################################################*/
//text button obj;
typedef struct {
    text_t *text;
    sfFloatRect hitbox;
    sfVector2f location;
    sfColor bn_color[on_hover + 1];
    void (*ptr)(void *value);
} button_text_t;
    #define START_MENU_SIZE 30
//0 - on_idle color, 1 - on_clikc, 2 - on_hover color
static const void *bn_states_color[] = {&sfYellow, &sfBlue, &sfRed};

/* this is an altarnitive for custom colors
static const sfColor bn_states_color[] = {
 {.a = , .b = , .g = , .r = },//idle
 {.a = , .b = , .g = , .r = },//on_click
 {.a = , .b = , .g = , .r = }};//on_hover */

//checks if the mouse is on the text button location
int is_mouse_on_btext(button_text_t *button, sfRenderWindow *window);
//creates a text button
button_text_t *init_button_text(sfVector2f position, void(*ptr)(void *),
sfFont *font, char *msg);
//destroys a text button
void destroy_button_text(button_text_t *button);
//changes the color of a text botton
void change_bntxt_color(button_text_t *button, button_state state);
////////////////////////////////////////////////////////////
/// \brief Makes an array of buttons pixels appart each
///
/// \param font     takes a pointer to a font
/// \param vect     innitial position of the first element
/// \param msg_arr  2d Array of the text for the options ending on a NULL
/// \param ptr      an array of function pointers should be the same len
/// as msg array
/// \return an array of text bottons ending on a NULL
///
///////////////////////////////////////////////////////////
button_text_t **set_up_menu_bntext(sfFont *font, sfVector2f vect,
char **msg_arr, void (*ptr[])(void *));
////////////////////////////////////////////////////////////
/// \brief draws the menu of text buttons with a specified offset from
/// eachohter
///
/// \param menu     pointer to the menu object already innited DO NOT PASS NULL
/// \param window   Render window object
/// \param offset_x the distance between the buttons on x axis can be negative
/// \param offset_y the distance between the buttons on y axis can be negative
///
///////////////////////////////////////////////////////////
void draw_menu_bntext(button_text_t **menu , sfRenderWindow *window,
float offset_x, float offset_y);
//destroys a menu from text bottons
void destroy_menu_bntext(button_text_t **menu);
//returns 1 if its clicked and 2 if it hovered
int is_click_or_hover_bntxt(button_text_t *button, sfEvent event);
//returns 1 if the mouse is on the botton and 0 if it not
int is_mouse_on_btext(button_text_t *button, sfRenderWindow *window);
//loops thoug a menu and passes the state obj to the func pointer
// void loop_menu(button_text_t *botton, states *state, sfEvent event,
// sfRenderWindow *window);
/*###########################################################################
#######################END OF TEXT BOTTONS SEGMENT###########################
-----------------------------------------------------------------------------*/
#endif /* !BUTTONS_H_ */
