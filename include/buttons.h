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

//contains the location, colors ,offset and font size of the button
typedef struct {
    sfVector2f location;
    void *bn_color[on_hover + 1];
    sfVector2f offset;
    int font_size;
    char is_for_single_use;
} button_text_info_t;

//checks if the mouse is on the text button location
int is_mouse_on_btext(button_text_t *button, sfRenderWindow *window);
////////////////////////////////////////////////////////////
/// \brief creates a text button
///
/// \param info    contains the location, colors ,offset and font
///                size of the button (offset is ignored here)
/// \param ptr     the function that will be called when the button is
///                clicked (parameter will be type cast in the function itself)
/// \param font    pointer to a font object
/// \param msg     string that will be displayed on the button
///
/// \return malloced button_text_t
///
///////////////////////////////////////////////////////////
button_text_t *init_button_text(button_text_info_t *info, void(*ptr)(void *),
sfFont *font, char *msg);
//destroys a text button
void destroy_button_text(button_text_t *button, int mask);
//changes the color of a text botton
void change_bntxt_color(button_text_t *button, button_state state);
////////////////////////////////////////////////////////////
/// \brief sets up the additional info needed for the text button
///
/// \param location   the location of the fist element for text button
/// \param color      an array of 3 colors casted as a void pointer
///                   0 - idle, 1 - on_click, 2 - on_hover takes const
/// \param offset     the offset between the different elements
///                   (can be negative) ignored for the first button
/// \param font_size  the size of the font for the buttons
///
/// \return malloced button_text_info_t that contains all of the parameters
///
///////////////////////////////////////////////////////////
button_text_info_t *init_button_text_info(sfVector2f location,
void const  **color, sfVector2f offset, int font_size);
////////////////////////////////////////////////////////////
/// \brief Makes an array of buttons pixels appart each
///
/// \param font     takes a pointer to a font
/// \param info     takes a pointer to a button_text_info_t innitilized
/// \param msg_arr  2d Array of the text for the options ending on a NULL
/// \param ptr      an array of function pointers should be the same len
///                 as msg array
/// \return an array of text bottons ending on a NULL
///
///////////////////////////////////////////////////////////
button_text_t **set_up_menu_bntext(sfFont *font, button_text_info_t *info,
char **msg_arr, void (*ptr[])(void *));
////////////////////////////////////////////////////////////
/// \brief draws the menu of text buttons with a specified offset from
/// eachohter
///
/// \param menu     pointer to the menu object already innited DO NOT PASS NULL
/// \param window   Render window object
///
///////////////////////////////////////////////////////////
void draw_menu_bntext(button_text_t **menu , sfRenderWindow *window);
//destroys a menu from text bottons
void destroy_menu_bntext(button_text_t **menu, int mask);
//returns 1 if its clicked and 2 if it hovered
int is_click_or_hover_bntxt(button_text_t *button, sfEvent event);
//returns 1 if the mouse is on the botton and 0 if it not
int is_mouse_on_btext(button_text_t *button, sfRenderWindow *window);
//loops thoug a menu and passes the state obj to the func pointer
// void loop_menu(button_text_t *botton, states *state, sfEvent event,
// sfRenderWindow *window);
////////////////////////////////////////////////////////////
/// \brief func used in a loop for the menu dispay in a evevent loop
///
/// \param button     the button to be operated on
/// \param element    thing that will be passed to the button func
///                   typecast must be done in the func itself
/// \param event      the event to be checked to see if the button is clicked
/// \param window     the window to be passed to the button func
///
///
///////////////////////////////////////////////////////////
void loop_menu(button_text_t *botton, void *element, sfEvent event,
sfRenderWindow *window);
/*###########################################################################
#######################END OF TEXT BOTTONS SEGMENT###########################
-----------------------------------------------------------------------------*/
#endif /* !BUTTONS_H_ */
